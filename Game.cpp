#include "Game.h"

int Game::loadTextures(int hero, int npc) {

    // load Player texture
    if (hero == 0) {
        if (!texturePlayer.loadFromFile("HeroTile.png")) {
            return EXIT_FAILURE;
        }
    } else if (hero == 1) {
        if (!texturePlayer.loadFromFile("WitchTile.png")) {
            return EXIT_FAILURE;
        }
    }
    else if (hero == 2) {
        if (!texturePlayer.loadFromFile("CoolHeroTile.png")) {
            return EXIT_FAILURE;
        }
    }

    // load NPC texture
    if (npc == 0) {
        if (!textureNPC.loadFromFile("Sheep.png")) {
            return EXIT_FAILURE;
        }
    }
    else if (npc == 1) {
        if (!textureNPC.loadFromFile("Dog.png")) {
            return EXIT_FAILURE;
        }
    }
    else if (npc == 2) {
        if (!textureNPC.loadFromFile("Cock.png")) {
            return EXIT_FAILURE;
        }
    }

    // load Enemies texture
    if (!textureAssassin.loadFromFile("Assassin.png")) {
        return EXIT_FAILURE;
    }
    if (!textureDarkLord.loadFromFile("DarkLord.png")) {
        return EXIT_FAILURE;
    }
    if (!textureChaos.loadFromFile("ChaosKnight.png")) {
        return EXIT_FAILURE;
    }
    if (!textureChimera.loadFromFile("Chimera.png")) {
        return EXIT_FAILURE;
    }
    if (!textureZombie.loadFromFile("Zombie.png")) {
        return EXIT_FAILURE;
    }

    // load Fireball texture
    if (!textureFireBall.loadFromFile("fireball.png")) {
        return EXIT_FAILURE;
    }

    // load Coin texture
    if (!textureCoin.loadFromFile("coin.png")) {
        return EXIT_FAILURE;
    }

    // load Profile texture
    if (!textureProfile.loadFromFile("Head.png")) {
        return EXIT_FAILURE;
    }

    // load Name texture
    if (!textureName.loadFromFile("Name.png")) {
        return EXIT_FAILURE;
    }

    // load Heart texture
    if (!textureHeart.loadFromFile("Hearts.png")) {
        return EXIT_FAILURE;
    }

    // load Experience texture
    if (!textureExp.loadFromFile("Experience.png")) {
        return EXIT_FAILURE;
    }

    // load Money texture
    if (!textureMoney.loadFromFile("Money.png")) {
        return EXIT_FAILURE;
    }

    // load Sword texture
    if (!textureSword.loadFromFile("Sword48.png")) {
        return EXIT_FAILURE;
    }

    // load Stick texture
    if (!textureStick.loadFromFile("Catalyst48.png")) {
        return EXIT_FAILURE;
    }

    // load Axe texture
    if (!textureAxe.loadFromFile("Axe48.png")) {
        return EXIT_FAILURE;
    }

    // load weapon texture
    if (!textureWeapon.loadFromFile("WeaponsSheet.png")) {
        return EXIT_FAILURE;
    }

    // load Potion texture
    if (!texturePotion.loadFromFile("PotionsSheet.png")) {
        return EXIT_FAILURE;
    }

    // load Scroll texture
    if (!textureScroll.loadFromFile("ScrollsSheet.png")) {
        return EXIT_FAILURE;
    }
}

void Game::setItems() {

    coinItem.setType("coin");
    coinItem.rect.setSize(sf::Vector2f(32, 32));
    coinItem.sprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
    coinItem.sprite.setTexture(textureCoin);


    swordItem.rect.setSize(sf::Vector2f(48, 48));
    swordItem.sprite.setTextureRect(sf::IntRect(0, 0, 48, 48));
    swordItem.sprite.setTexture(textureSword);


    stickItem.rect.setSize(sf::Vector2f(48, 48));
    stickItem.sprite.setTextureRect(sf::IntRect(0, 0, 48, 48));
    stickItem.sprite.setTexture(textureStick);


    axeItem.rect.setSize(sf::Vector2f(48, 48));
    axeItem.sprite.setTextureRect(sf::IntRect(0, 0, 48, 48));
    axeItem.sprite.setTexture(textureAxe);
}

void Game::setEnemies() {

    darkLord.rect.setPosition(200, 400);
    darkLord.sprite.setTexture(textureDarkLord);

    assassin.rect.setPosition(300, 500);
    assassin.sprite.setTexture(textureAssassin);

    zombie.rect.setPosition(700, 350);
    zombie.sprite.setTexture(textureZombie);

    chimera.rect.setPosition(500, 550);
    chimera.sprite.setTexture(textureChimera);

    chaosKnight.rect.setPosition(500, 200);
    chaosKnight.sprite.setTexture(textureChaos);
}

void Game::setSprites(int choose) {
    // Head sprite
    headSprite.setTexture(textureProfile);
    headSprite.setTextureRect(sf::IntRect(choose * 150, 0, 150, 164));
    headSprite.setPosition(0, 0);

    // Name sprite
    nameSprite.setTexture(textureName);
    nameSprite.setTextureRect(sf::IntRect(0, 0, 150, 54));
    nameSprite.setPosition(0, 164);

    // Hearts sprite
    heartsSprite.setTexture(textureHeart);
    heartsSprite.setTextureRect(sf::IntRect(0, 0, 150, 36));
    heartsSprite.setPosition(0, 218);

    // Experience sprite
    expSprite.setTexture(textureExp);
    expSprite.setTextureRect(sf::IntRect(0, 0, 150, 59));
    expSprite.setPosition(0, 254);

    // Money sprite
    moneySprite.setTexture(textureMoney);
    moneySprite.setTextureRect(sf::IntRect(0, 0, 150, 61));
    moneySprite.setPosition(0, 313);

    // Weapons sprite
    weaponsSprite.setTexture(textureWeapon);
    weaponsSprite.setTextureRect(sf::IntRect(0, 0, 150, 76));
    weaponsSprite.setPosition(0, 374);

    // Potions sprite
    potionsSprite.setTexture(texturePotion);
    potionsSprite.setTextureRect(sf::IntRect(0, 0, 150, 70));
    potionsSprite.setPosition(0, 450);

    // Scrolls sprite
    scrollsSprite.setTexture(textureScroll);
    scrollsSprite.setTextureRect(sf::IntRect(0, 0, 150, 80));
    scrollsSprite.setPosition(0, 520);
}

void Game::personalizeHero(Hero &hero, int choose) {
    switch (choose) {
        case 0:
            hero.setWeapon(&sword);
            weaponsSprite.setTextureRect(sf::IntRect(0, 76, 150, 76));
            hero.setPotion(&bluePotion);
            potionsSprite.setTextureRect(sf::IntRect(0, 280, 150, 70));
            hero.setChangeToSword(true);
            scrollsSprite.setTextureRect(sf::IntRect(0, 480, 150, 80));
            hero.setMoney(200);
            hero.text.setString(std::to_string(hero.getMoney()));
            break;
        case 1:
            hero.setWeapon(&stick);
            weaponsSprite.setTextureRect(sf::IntRect(0, 152, 150, 76));
            hero.setPotion(&redPotion);
            potionsSprite.setTextureRect(sf::IntRect(0, 420, 150, 70));
            hero.setChangeToStick(true);
            scrollsSprite.setTextureRect(sf::IntRect(0, 480, 150, 80));
            hero.setMoney(220);
            hero.text.setString(std::to_string(hero.getMoney()));
            break;
        case 2:
            hero.setWeapon(&axe);
            weaponsSprite.setTextureRect(sf::IntRect(0, 228, 150, 76));
            hero.setPotion(&greenPotion);
            potionsSprite.setTextureRect(sf::IntRect(0, 350, 150, 70));
            hero.setChangeToAxe(true);
            scrollsSprite.setTextureRect(sf::IntRect(0, 480, 150, 80));
            hero.setMoney(250);
            hero.text.setString(std::to_string(hero.getMoney()));
            break;
    }
}

void Game::setHeroBar(Hero &hero) {
    // Set Hearts, Exp, Weapon and Potion sprites
    hero.setHeartsSprite(heartsSprite);
    hero.setExpSprite(expSprite);
    hero.setWeaponSprite(weaponsSprite);
    hero.setPotionsSprite(potionsSprite);
}

void Game::setHeroText(Hero &hero) {
    // Money text
    hero.text.setFont(font);
    hero.text.setString(std::to_string(hero.getMoney()));
    hero.text.setCharacterSize(30);
    hero.text.setColor(sf::Color::Red);
    hero.text.setPosition(80, 315);
}

void Game::setFont() {
    font.loadFromFile("PrinceValiant.ttf");
}

int Game::setMusic() {
    if (!music.openFromFile("Elite4Cut.ogg")) {
        return EXIT_FAILURE;
    }
    music.play();
    music.setLoop(true);
    music.setVolume(20);
    // Sound effects

    if (!bufferShot.loadFromFile("shot.ogg"))
        return -1;

    soundShot.setBuffer(bufferShot);
    soundShot.setVolume(10);
}