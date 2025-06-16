#include <Geode/Geode.hpp>

using namespace geode::prelude;

#include <Geode/modify/EditLevelLayer.hpp>

class $modify(MyEditLevelLayer, EditLevelLayer){
	bool init(GJGameLevel* p0) {
		if (!EditLevelLayer::init(p0)) return false;
		auto menu = getChildByID("folder-menu");
		auto coin = CCSprite::createWithSpriteFrameName("GJ_coinsIcon2_001.png");
		auto spr = CircleButtonSprite::create(coin, CircleBaseColor::Green, CircleBaseSize::Small);
		auto btn = CCMenuItemSpriteExtra::create(spr, this, menu_selector(MyEditLevelLayer::onMyButton));
		coin->setScale(0.8);
		menu->addChild(btn);
		menu->updateLayout();
		return true;
	}

	void onMyButton(CCObject*) {
		auto popup = SetIDPopup::create(m_level->m_coins, -10000, 10000, "Coin Amount", "SET", 1, 0, 1, 1, 1);
		popup->setID("popup"_spr);
		popup->show();
		popup->m_delegate = this;
	}

	void setIDPopupClosed(SetIDPopup* p0, int p1) {
		if (p0->getID() == "popup"_spr) {
			m_level->m_coins = p1;
		} else {
			EditLevelLayer::setIDPopupClosed(p0, p1);
		}
	}
};