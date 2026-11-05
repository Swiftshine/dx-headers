#pragma once

#include <Types.h>

#include <layer/aglRenderInfo.h>

#include <euiAnimator.h>
#include <euiDrawInfoEx.h>
#include <euiLayoutEx.h>
#include <euiTextBoxEx.h>
#include <euiTagProcessor.h>

#include <nn/ui2d/ui2d_Animator.h>
#include <nn/ui2d/ui2d_Bounding.h>
#include <nn/ui2d/ui2d_Layout.h>
#include <nn/ui2d/ui2d_Parts.h>
#include <nn/ui2d/ui2d_Picture.h>
#include <nn/ui2d/ui2d_Window.h>

#include <container/seadStrTreeMap.h>
#include <gfx/seadGraphicsContext.h>
#include <heap/seadDisposer.h>
#include <math/seadMatrix.h>
#include <prim/seadSafeString.h>

class AppScreen;

// vtable Address: 0x60BFCA78
class AnimLayoutBase : public sead::IDisposer {
public:
    class AnimBuffer;
    struct AnimTagInfo;

public:
    AnimLayoutBase(AnimBuffer* anim_buffer, u32 anim_buffer_size) {
        // todo
    }

    ~AnimLayoutBase() override;

    virtual void animeSetup(const sead::SafeString*, const s32&);
    virtual void createScreen_(sead::Heap* heap);
    virtual void* getScreenPtr_();

    // Address: 0x604735D4
    void prepare(sead::Heap* heap, AppScreen* app_screen = nullptr);

    // Address: 0x60473624
    void buildAnimTag(const sead::SafeString&);

    // Address: 0x604739E8
    void updateAllImpl_(const sead::Matrix34f&, const sead::Matrix34f*);
    
    nn::ui2d::Pane* getRootPane();
    void updateAllImpl(s32, const sead::Matrix34f*);
    void draw(const agl::lyr::RenderInfo& render_info, const sead::GraphicsContext& graphics_context);
    void draw(const eui::DrawInfoEx::RenderBufferInfo&, const sead::Matrix34f&);
    const sead::SafeString getName() const;
    void setAnimTag(s32, const sead::SafeString&, nn::ui2d::Animator::PlayType play_type);
    void setAnimTagImpl_(s32, const sead::SafeString&, nn::ui2d::Animator::PlayType play_type, eui::Animator*, f32);
    void setReverseAnimTag(s32, const sead::SafeString&, nn::ui2d::Animator::PlayType);
    void setAnimTagWithGroupIdx(s32, const sead::SafeString&, u32 group_index, nn::ui2d::Animator::PlayType play_type, f32);
    void setReverseAnimTagWithGroupIdx(s32, const sead::SafeString&, u32 group_index, nn::ui2d::Animator::PlayType play_type);
    void setAnimeFrame(s32, f32);
    f32 getAnimeFrame(s32) const;
    void setAnimeStop(s32);
    f32 getMaxFrame(s32) const;
    void setPlaySpeed(s32, nn::ui2d::Animator::PlayType play_type, f32 play_speed);
    void playAnimatorWithGroup(s32, const sead::SafeString&, const sead::SafeString&, nn::ui2d::Animator::PlayType play_type, f32);
    s32 findAnimTagGroupIdx(const sead::SafeString&, const sead::SafeString&);
    void* getAnimTag(s32) const;
    nn::ui2d::Animator* getAnimator(s32) const;
    nn::ui2d::Pane* getRootPane() const;
    nn::ui2d::Pane* findPaneByName_(const sead::SafeString& pane_name);
    void* findPictureByName_(const sead::SafeString& picture_name);
    void* findTextBoxEx_(const sead::SafeString&);
    void* findBoundingByName_(const sead::SafeString& bounding_name);
    void* findWindowByName_(const sead::SafeString& window_name);
    void* getPartsLayoutByName(const sead::SafeString& parts_layout_name);
    void* findGroupByName(const sead::SafeString& group_name);
    void adjustPaneSizeToTextSizeAll();
    bool isNecessaryToAdjustPaneSizeToTextSize() const;
    void setupImpl_();
    void* findPartsLayoutByName(const sead::SafeString& parts_layout_name);
    void* findPartsByName(const sead::SafeString& parts_name);
    void setNPaneRegister(nn::ui2d::Pane**, const sead::SafeString*, const s32&);
    void trySetNPaneRegister(nn::ui2d::Pane**, const sead::SafeString*, const s32&);
    void setPPaneRegister(nn::ui2d::Picture**, const sead::SafeString*, const s32&);
    void trySetPPaneRegister(nn::ui2d::Picture**, const sead::SafeString*, const s32&);
    void setTPaneRegister(eui::TextBoxEx**, const sead::SafeString*, const s32&);
    void trySetTPaneRegister(eui::TextBoxEx**, const sead::SafeString*, const s32&);
    void setBPaneRegister(nn::ui2d::Bounding**, const sead::SafeString*, const s32&);
    void trySetBPaneRegister(nn::ui2d::Bounding**, const sead::SafeString*, const s32&);
    void setWPaneRegister(nn::ui2d::Window**, const sead::SafeString*, const s32&);
    void setPartsRootPaneRegister(nn::ui2d::Pane**, const sead::SafeString*, const s32&);
    void setPartsTPaneRegister(eui::TextBoxEx**, const sead::SafeString&, const sead::SafeString*, const s32&);
    void setPartsBPaneRegister(nn::ui2d::Bounding**, const sead::SafeString&, const sead::SafeString*, const s32&);
    void setPartsPPaneRegister(nn::ui2d::Picture**, const sead::SafeString&, const sead::SafeString*, const s32&);
    void setPartsNPaneRegister(nn::ui2d::Pane**, const sead::SafeString&, const sead::SafeString*, const s32&);
    void setPartsWPaneRegister(nn::ui2d::Window**, const sead::SafeString&, const sead::SafeString*, const s32&);
    void setPaPaneRegister(nn::ui2d::Parts**, const sead::SafeString&);
    f32 getLeftPaneSize_(const eui::TextBoxEx*);
    f32 getRightPaneSize_(const eui::TextBoxEx*);
    void setTwoTextPaneCenter(nn::ui2d::Pane*, nn::ui2d::Pane*, nn::ui2d::Pane*, const eui::TextBoxEx*, const eui::TextBoxEx*);
    bool IsContain(const sead::Vector2f&);
    // Address: 0x6047572C
    void setPlayerColor(const sead::SafeString&, s32, s32, bool);
    void chgUseProCon(eui::TextBoxEx*, bool);

protected:
    eui::LayoutEx* mLayout;
    sead::Heap* mLayoutAllocator;
    eui::DrawInfoEx* mDrawInfo;
    u32 _1c;
    sead::StrTreeMap<64, AnimTagInfo> mAnimTagMap;
    u8 _34[0xDB4 - 0x34];
    u32 mAnimBufferSize;
    AnimBuffer* mAnimBuffer;
    eui::TagProcessor* mTagProcessor;
};
SIZE_ASSERT(AnimLayoutBase, 0xDC0);
