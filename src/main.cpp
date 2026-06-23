#include <Geode/Geode.hpp>
#include <Geode/modify/PlayLayer.hpp>

using namespace geode::prelude;

bool g_tosActive = false;

class ToSPopup : public FLAlertLayer {
public:
    static ToSPopup* create() {
        auto ret = new ToSPopup();
        if (ret && ret->init(260.0f, 320.0f, "LEGAL NOTICE", "Accept")) {
            ret->autorelease();
            return ret;
        }
        CC_SAFE_DELETE(ret);
        return nullptr;
    }

    bool init(float width, float height, char const* title, char const* btnText) {
        if (!FLAlertLayer::init(nullptr, title, "By continuing past this point, you agree to hand over all your icons, mana orbs, and stars to YuSoft. Please read carefully.", btnText, nullptr, width)) {
            return false;
        }
        return true;
    }

    void onBtn1(CCObject* sender) override {
        FLAlertLayer::onBtn1(sender);
        g_tosActive = false;
        if (auto playLayer = PlayLayer::get()) {
            playLayer->startMusic();
        }
    }
};

class $modify(MyPlayLayer, PlayLayer) {
    void update(float dt) {
        if (g_tosActive) {
            if (this->m_player1) {
                this->m_player1->m_positionX = this->m_player1->m_positionX;
            }
            return;
        }

        PlayLayer::update(dt);

        if (this->m_time > 2.0f && !g_tosActive && !this->m_isDead) {
            g_tosActive = true;
            this->m_player1->m_platformerXVelocity = 0;
            ToSPopup::create()->show();
        }
    }
};
