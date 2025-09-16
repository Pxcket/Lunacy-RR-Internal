#include "menu.h"
#include "../dependencies/imgui/imgui.h"
#include "../dependencies/imgui/imgui_internal.h"
#include <cmath>
#include <cstdio>

namespace pGui {

    static inline ImU32 MulA(ImU32 c, float mul) {
        ImVec4 v = ImGui::ColorConvertU32ToFloat4(c);
        if (mul < 0.0f) mul = 0.0f; if (mul > 1.0f) mul = 1.0f;
        v.w *= mul;
        return ImGui::ColorConvertFloat4ToU32(v);
    }
    static inline ImU32 RGBAf(float r, float g, float b, float a) {
        int R = (int)(r * 255.0f), G = (int)(g * 255.0f), B = (int)(b * 255.0f), A = (int)(a * 255.0f);
        if (R < 0)R = 0; if (R > 255)R = 255; if (G < 0)G = 0; if (G > 255)G = 255; if (B < 0)B = 0; if (B > 255)B = 255; if (A < 0)A = 0; if (A > 255)A = 255;
        return IM_COL32(R, G, B, A);
    }
    static inline float Px(float x) { return IM_ROUND(x); }

    void Watermark(const char* title)
    {
        ImGuiIO& io = ImGui::GetIO();
        ImDrawList* draw = ImGui::GetForegroundDrawList();

        const ImU32 col_bg_main = IM_COL32(22, 22, 27, 245);
        const ImU32 col_border = IM_COL32(255, 255, 255, 230);
        const ImU32 col_text = IM_COL32(255, 255, 255, 255);
        const ImU32 col_dim = IM_COL32(180, 180, 200, 230);
        const ImU32 col_sheen = IM_COL32(255, 255, 255, 40);
        const ImU32 col_accent = RGBAf(0.74f, 0.58f, 0.98f, 1.0f);

        const float padX = 10.0f;
        const float padY = 6.0f;
        const float rounding = 8.0f;
        const float border_thickness = 1.5f;

        static float fpsEma = 0.0f;
        const float k = 1.0f - std::exp(-io.DeltaTime * 6.0f);
        fpsEma += (io.Framerate - fpsEma) * k;
        const float ms = (fpsEma > 0.001f) ? (1000.0f / fpsEma) : 0.0f;

        char line[256];
        std::snprintf(line, sizeof(line), "%s  |  %.1f FPS", title, fpsEma); //Already Removed ms nvm, still add the pulsing animation thingy on the left, 
        ImVec2 textSize = ImGui::CalcTextSize(line); //also make the animation like follow the little circle rectangle its in, really retard code

        const ImVec2 basePos = ImVec2(16.0f, 16.0f);
        const ImVec2 boxSize = ImVec2(textSize.x + padX * 2.0f, textSize.y + padY * 2.0f);


        static float t = 0.0f; t += io.DeltaTime * 2.0f; if (t > 1.0f) t = 1.0f;
        const float e = t * t * (3.0f - 2.0f * t); 
        const float slideOffset = (1.0f - e) * 24.0f;
        const float alphaMul = e;

        ImVec2 pos = ImVec2(Px(basePos.x - slideOffset), Px(basePos.y));
        ImVec2 rectMin = ImVec2(Px(pos.x), Px(pos.y));
        ImVec2 rectMax = ImVec2(Px(pos.x + boxSize.x), Px(pos.y + boxSize.y));


        {
            ImVec2 smin = ImVec2(Px(rectMin.x + 2.0f), Px(rectMin.y + 2.0f));
            ImVec2 smax = ImVec2(Px(rectMax.x + 2.0f), Px(rectMax.y + 2.0f));
            draw->AddRectFilled(smin, smax, MulA(IM_COL32(0, 0, 0, 90), alphaMul * 0.35f), rounding + 2.0f);
        }


        draw->AddRectFilled(rectMin, rectMax, MulA(col_bg_main, alphaMul), rounding);


        {

            float h = 6.0f;
            ImVec2 tmin = ImVec2(Px(rectMin.x + 1.0f), Px(rectMin.y + 1.0f));
            ImVec2 tmax = ImVec2(Px(rectMax.x - 1.0f), Px(rectMin.y + h));
            draw->AddRectFilled(tmin, tmax, MulA(IM_COL32(255, 255, 255, 16), alphaMul), rounding);

            ImVec2 bmin = ImVec2(Px(rectMin.x + 1.0f), Px(rectMax.y - h));
            ImVec2 bmax = ImVec2(Px(rectMax.x - 1.0f), Px(rectMax.y - 1.0f));
            draw->AddRectFilled(bmin, bmax, MulA(IM_COL32(0, 0, 0, 40), alphaMul), rounding);
        }


        draw->AddRect(rectMin, rectMax, MulA(col_border, alphaMul), rounding, 0, border_thickness);


        {
            static float glowT = 0.0f; glowT += io.DeltaTime;
            float pulse = 0.5f + 0.5f * std::sinf(glowT * 2.3f);
            float glowAlpha = 0.12f + 0.20f * pulse;
            ImVec2 gmin = ImVec2(Px(rectMin.x - 1.0f), Px(rectMin.y - 1.0f));
            ImVec2 gmax = ImVec2(Px(rectMax.x + 1.0f), Px(rectMax.y + 1.0f));
            draw->AddRect(gmin, gmax, MulA(col_accent, alphaMul * glowAlpha), rounding + 1.0f, 0, 2.0f);
        }


        const float safeInset = rounding + 2.0f;     
        const float usableW = (boxSize.x - safeInset * 2.0f);
        const float topY1 = Px(rectMin.y + 2.0f);
        const float topY2 = Px(rectMin.y + 4.0f);
        const float botY1 = Px(rectMax.y - 3.0f);
        const float botY2 = Px(rectMax.y - 1.0f);


        {
            static float tSweep = 0.0f; tSweep += io.DeltaTime;
            float stripW = ImClamp(usableW * 0.20f, 18.0f, 110.0f);
            float phase = std::fmod(tSweep, 2.0f) / 2.0f; 
            float x = Px(rectMin.x + safeInset + phase * (usableW - stripW));

            ImU32 accentSoft = MulA(col_accent, alphaMul * 0.35f);
            ImU32 accentHard = MulA(col_accent, alphaMul * 0.75f);
            ImVec2 aMin = ImVec2(x, topY1);
            ImVec2 aMax = ImVec2(x + stripW, topY2);
            draw->AddRectFilled(aMin, aMax, accentSoft, 2.0f);
            ImVec2 midMin = ImVec2(Px(x + stripW * 0.25f), topY1);
            ImVec2 midMax = ImVec2(Px(x + stripW * 0.75f), topY2);
            draw->AddRectFilled(midMin, midMax, accentHard, 2.0f);
        }


        {
            static float timeAcc = 0.0f; timeAcc += io.DeltaTime;
            float sheenW = ImClamp(usableW * 0.18f, 20.0f, 120.0f);
            float phase = std::fmod(timeAcc, 2.4f) / 2.4f;
            float xSheen = Px(rectMin.x + safeInset + phase * (usableW - sheenW));

            ImVec2 sMin = ImVec2(xSheen, botY1);
            ImVec2 sMax = ImVec2(xSheen + sheenW, botY2);
            draw->AddRectFilled(sMin, sMax, MulA(col_sheen, alphaMul * 0.9f), 2.0f); //why is this so retarded im killing myself, god, FUCKIGN NIGGERS
        }


        ImVec2 textPos = ImVec2(Px(pos.x + padX), Px(pos.y + padY));
        draw->AddText(ImVec2(textPos.x, textPos.y + 1.0f), MulA(col_dim, alphaMul * 0.6f), line);
        draw->AddText(textPos, MulA(col_text, alphaMul), line);


        float dotPulse2 = 0.5f + 0.5f * std::sinf(ImGui::GetTime() * 3.2f); //Byte add this bs at the left side aswell, And Fix The Animation You Faggot
        float r = 2.0f + dotPulse2 * 0.8f;
        ImVec2 center = ImVec2(Px(rectMax.x - padX * 0.6f), Px(rectMin.y + boxSize.y * 0.5f));
        draw->AddCircleFilled(center, r, MulA(col_accent, alphaMul * (0.5f + 0.5f * dotPulse2)), 24);
    }

} 
