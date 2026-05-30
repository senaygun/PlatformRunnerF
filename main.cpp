#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <string>
#include <cstring>

const int TILE_SIZE = 40;
const int MAP_WIDTH = 40;
const int MAP_HEIGHT = 15;
const int MAX_LEVEL = 3;

int mevcutlevel = 0;

const int levels[MAX_LEVEL][MAP_HEIGHT][MAP_WIDTH] = {
    {//Level 1
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,2,2,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0, 0,0,0,0,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,1,0,0, 0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1, 0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0},
        {1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,1, 1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0},
        {1,0,0,0,0,2,1,1,1,1,0,5,0,0,0,0,0,0,0,1, 1,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,4},
        {1,0,0,0,1,1,1,0,0,0,1,1,1,1,1,1,0,0,0,1, 1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,4},
        {1,1,1,1,1,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1, 1,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1},
        {1,1,1,1,1,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1, 1,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1},
        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
    },
    //Level 2
    {
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,2, 2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1, 1,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,2,2,0,0,0,0,0,0,0,0,0,0,0,0, 0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,1,1,1,1,0,0,0,0,6,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0},
        {1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0},
        {1,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
        {1,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,1,1,1,0, 0,0,1,1,0,0,0,1,1,1,0,0,0,1,1,1,0,0,0,4},
        {1,1,1,1,1,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3, 3,3,3,3,3,3,3,3,3,3,3,3,3,1,1,1,1,1,1,1},
        {1,1,1,1,1,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3, 3,3,3,3,3,3,3,3,3,3,3,3,3,1,1,1,1,1,1,1},
        {1,1,1,1,1,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3, 3,3,3,3,3,3,3,3,3,3,3,3,3,1,1,1,1,1,1,1}
    },
    //Level 3
    {
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1, 0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,2,0,0,0,0,0,1,1,1,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,1,1,1,0,0,6,0,0,0,0,0, 0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {1,1,0,0,0,1,1,1,0,0,0,0,0,0,0,2,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,5, 0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,4},
        {1,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,1,1, 1,0,0,1,0,0,0,0,0,0,1,1,1,0,0,0,1,1,1,4},
        {1,1,3,3,1,3,3,3,3,3,1,3,3,3,3,3,3,3,3,3, 3,3,3,1,3,3,3,3,3,3,3,3,3,3,3,3,1,1,1,1},
        {1,1,3,3,1,3,3,3,3,3,1,3,3,3,3,3,3,3,3,3, 3,3,3,1,3,3,3,3,3,3,3,3,3,3,3,3,1,1,1,1},
        {1,1,3,3,1,3,3,3,3,3,1,3,3,3,3,3,3,3,3,3, 3,3,3,1,3,3,3,3,3,3,3,3,3,3,3,3,1,1,1,1}
    }
};

class Mermi {
public:
    sf::FloatRect sinirlar;
    float hizX;
    bool yasiyor = true;

    Mermi(float baslangicX, float baslangicY, bool sagaGidiyor) {
        sinirlar = sf::FloatRect(baslangicX, baslangicY, 15.0f, 6.0f);
        hizX = sagaGidiyor ? 700.0f : -700.0f;
    }

    void guncelle(float dt) {
        if (!yasiyor) return;
        sinirlar.left += hizX * dt;
    }
};

class Dusman {
public:
    sf::FloatRect sinirlar;
    float hizX;
    float solSinir;
    float sagSinir;
    bool yasiyor = true;

    Dusman(float baslangicX, float baslangicY) {
        sinirlar = sf::FloatRect(baslangicX, baslangicY, 40.0f, 40.0f);
        hizX = 100.0f;
        solSinir = baslangicX - 80.0f;
        sagSinir = baslangicX + 80.0f;
    }

    void guncelle(float dt) {
        if (!yasiyor) return;
        sinirlar.left += hizX * dt;
        if (sinirlar.left <= solSinir || sinirlar.left >= sagSinir) {
            hizX = -hizX;
        }
    }
};

class HareketliPlatform {
public:
    sf::FloatRect sinirlar;
    float hizX;
    float solSinir;
    float sagSinir;

    HareketliPlatform(float baslangicX, float baslangicY) {
        sinirlar = sf::FloatRect(baslangicX, baslangicY, 80.0f, 20.0f);
        hizX = 100.0f;
        solSinir = baslangicX - 40.0f;
        sagSinir = baslangicX + 160.0f;
    }

    void guncelle(float dt) {
        sinirlar.left += hizX * dt;
        if (sinirlar.left <= solSinir || sinirlar.left >= sagSinir) {
            hizX = -hizX;
        }
    }
};

class oyuncu {
public:
    sf::FloatRect sinirlar;
    sf::Texture doku;
    sf::Sprite sprite;
    bool gorselYuklendiMi = false;
    float zamanlayici = 0.0f;
    int mevcutKare = 0;
    bool sagabakiyor = true;

    float hizX = 0.0f;
    float hizY = 0.0f;
    float harekethizi = 250.0f;
    float ziplamagucu = -450.0f;
    float yercekimi = 980.0f;
    bool yerdemi = false;
    int ziplamaSayisi = 0;
    bool oncekiZiplamaDurumu = false;

    oyuncu(float baslangicX, float baslangicY) {
        sinirlar = sf::FloatRect(baslangicX, baslangicY, 30.0f, 30.0f);

        if (doku.loadFromFile("player.png")) {
            gorselYuklendiMi = true;
            sprite.setTexture(doku);
            sprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
        }
    }

    void guncelle(float dt) {
        hizX = 0.0f;

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            hizX = harekethizi;
            sagabakiyor = true;
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            hizX = -harekethizi;
            sagabakiyor = false;
        }

        bool mevcutZiplamaDurumu = sf::Keyboard::isKeyPressed(sf::Keyboard::Up);

        if (mevcutZiplamaDurumu && !oncekiZiplamaDurumu && ziplamaSayisi < 2) {
            hizY = ziplamagucu;
            ziplamaSayisi++;
            yerdemi = false;
        }
        oncekiZiplamaDurumu = mevcutZiplamaDurumu;

        hizY += yercekimi * dt;

        if (gorselYuklendiMi) {
            zamanlayici += dt;
            if (hizX != 0.0f) {
                if (zamanlayici > 0.1f) {
                    mevcutKare = (mevcutKare + 1) % 4;
                    sprite.setTextureRect(sf::IntRect(mevcutKare * 32, 0, 32, 32));
                    zamanlayici = 0.0f;
                }
            } else {
                sprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
            }
        }

        if (!sagabakiyor) {
            sprite.setScale(-1.0f, 1.0f);
            sprite.setOrigin(32.0f, 0.0f);
        } else {
            sprite.setScale(1.0f, 1.0f);
            sprite.setOrigin(0.0f, 0.0f);
        }
    }
};

int main()
{
    sf::RenderWindow pencere(sf::VideoMode(800, 600), "Platform Oyunu");
    pencere.setFramerateLimit(60);
    sf::Clock saat;
    sf::View kamera(sf::FloatRect(0, 0, 800, 600));
    oyuncu karakter(50.0f, 300.0f);
    sf::RectangleShape zeminsekli(sf::Vector2f(TILE_SIZE, TILE_SIZE));

    sf::Texture arkaplanDokusu;
    sf::Sprite arkaplanSprite;
    bool arkaplanYuklendiMi = false;

    if (arkaplanDokusu.loadFromFile("background.png")) {
        arkaplanDokusu.setRepeated(true);
        arkaplanSprite.setTexture(arkaplanDokusu);
        arkaplanSprite.setTextureRect(sf::IntRect(0, 0, 800, 600));
        arkaplanYuklendiMi = true;
    } else {
        std::cout << "!background.png BULUNAMADI!" << std::endl;
    }

    sf::CircleShape altintop(10.0f);
    altintop.setFillColor(sf::Color::Yellow);

    sf::RectangleShape dusmanSekli(sf::Vector2f(TILE_SIZE, TILE_SIZE));
    dusmanSekli.setFillColor(sf::Color::Blue);

    sf::RectangleShape platformSekli;
    platformSekli.setFillColor(sf::Color(150, 150, 150));

    std::vector<Mermi> mermiler;
    sf::RectangleShape mermiSekli(sf::Vector2f(15.0f, 6.0f));
    mermiSekli.setFillColor(sf::Color(255, 165, 0));
    float mermiBekleme = 0.0f;

    int skor = 0;
    int activeLevels[MAX_LEVEL][MAP_HEIGHT][MAP_WIDTH];
    std::memcpy(activeLevels, levels, sizeof(levels));

    std::vector<Dusman> dusmanlar;
    std::vector<HareketliPlatform> platformlar;

    auto seviyeyiYukle = [&]() {
        dusmanlar.clear();
        platformlar.clear();
        mermiler.clear();
        for (int y = 0; y < MAP_HEIGHT; y++) {
            for (int x = 0; x < MAP_WIDTH; x++) {
                if (activeLevels[mevcutlevel][y][x] == 5) {
                    dusmanlar.push_back(Dusman(x * TILE_SIZE, y * TILE_SIZE));
                    activeLevels[mevcutlevel][y][x] = 0;
                } else if (activeLevels[mevcutlevel][y][x] == 6) {
                    platformlar.push_back(HareketliPlatform(x * TILE_SIZE, y * TILE_SIZE));
                    activeLevels[mevcutlevel][y][x] = 0;
                }
            }
        }
        };

    seviyeyiYukle();

    sf::Font font;
    if (!font.loadFromFile("CENTURY.ttf")) {
        std::cout << "ERROR: dosya bulunamadi!" << std::endl;
    }
    sf::Text skoryazisi;
    skoryazisi.setFont(font);
    skoryazisi.setCharacterSize(24);
    skoryazisi.setFillColor(sf::Color::White);

    bool oyunBitti = false;

    sf::Text oyunBittiYazisi;
    oyunBittiYazisi.setFont(font);
    oyunBittiYazisi.setCharacterSize(45);
    oyunBittiYazisi.setFillColor(sf::Color::Red);
    oyunBittiYazisi.setString("GAME OVER");

    sf::Text restartYazisi;
    restartYazisi.setFont(font);
    restartYazisi.setCharacterSize(22);
    restartYazisi.setFillColor(sf::Color::White);
    restartYazisi.setString("PRESS -R- TO RESTART");

    sf::RectangleShape yaziArkaplan(sf::Vector2f(750.0f, 130.0f));
    yaziArkaplan.setFillColor(sf::Color(30, 30, 30, 220));

    while (pencere.isOpen()) {
        float dt = saat.restart().asSeconds();
        sf::Event olay;
        while (pencere.pollEvent(olay)) {
            if (olay.type == sf::Event::Closed) {
                pencere.close();
            }
        }

        if (!oyunBitti) {
            karakter.guncelle(dt);

            if (mermiBekleme > 0.0f) mermiBekleme -= dt;
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && mermiBekleme <= 0.0f) {
                float mermiX = karakter.sagabakiyor ? karakter.sinirlar.left + 30.0f : karakter.sinirlar.left - 15.0f;
                float mermiY = karakter.sinirlar.top + 15.0f;
                mermiler.push_back(Mermi(mermiX, mermiY, karakter.sagabakiyor));
                mermiBekleme = 0.3f;
            }
            for (auto& m : mermiler) m.guncelle(dt);
            for (auto& d : dusmanlar) d.guncelle(dt);
            for (auto& p : platformlar) p.guncelle(dt);

            for (auto& m : mermiler) {
                if (!m.yasiyor) continue;

                for (auto& d : dusmanlar) {
                    if (d.yasiyor && m.sinirlar.intersects(d.sinirlar)) {
                        d.yasiyor = false;
                        m.yasiyor = false;
                        skor += 20;
                        break;
                    }
                }

                if (m.yasiyor) {
                    int gridX = m.sinirlar.left / TILE_SIZE;
                    int gridY = m.sinirlar.top / TILE_SIZE;

                    if (gridX >= 0 && gridX < MAP_WIDTH && gridY >= 0 && gridY < MAP_HEIGHT) {
                        if (activeLevels[mevcutlevel][gridY][gridX] == 1) {
                            m.yasiyor = false;
                        }
                    } else {
                        m.yasiyor = false;
                    }
                }
            }

            karakter.sinirlar.left += karakter.hizX * dt;
            for (int y = 0;y < MAP_HEIGHT;y++) {
                for (int x = 0;x < MAP_WIDTH;x++) {
                    if (activeLevels[mevcutlevel][y][x] == 1) {
                        sf::FloatRect bloksiniri(x * TILE_SIZE, y * TILE_SIZE, TILE_SIZE, TILE_SIZE);
                        if (karakter.sinirlar.intersects(bloksiniri)) {
                            if (karakter.hizX > 0) {
                                karakter.sinirlar.left = bloksiniri.left - karakter.sinirlar.width;
                            } else if (karakter.hizX < 0) {
                                karakter.sinirlar.left = bloksiniri.left + bloksiniri.width;
                            }
                            karakter.hizX = 0;
                        }
                    }
                }
            }

            karakter.sinirlar.top += karakter.hizY * dt;
            karakter.yerdemi = false;

            for (int y = 0;y < MAP_HEIGHT;y++) {
                for (int x = 0;x < MAP_WIDTH;x++) {
                    if (activeLevels[mevcutlevel][y][x] == 1) {
                        sf::FloatRect bloksiniri(x * TILE_SIZE, y * TILE_SIZE, TILE_SIZE, TILE_SIZE);
                        if (karakter.sinirlar.intersects(bloksiniri)) {
                            if (karakter.hizY > 0) {
                                karakter.sinirlar.top = bloksiniri.top - karakter.sinirlar.height;
                                karakter.yerdemi = true;
                                karakter.ziplamaSayisi = 0;
                            } else if (karakter.hizY < 0) {
                                karakter.sinirlar.top = bloksiniri.top + bloksiniri.height;
                            }
                            karakter.hizY = 0;
                        }
                    }
                }
            }

            for (auto& p : platformlar) {
                if (karakter.sinirlar.intersects(p.sinirlar)) {
                    if (karakter.hizY > 0 && karakter.sinirlar.top + karakter.sinirlar.height < p.sinirlar.top + 25.0f) {
                        karakter.sinirlar.top = p.sinirlar.top - karakter.sinirlar.height;
                        karakter.yerdemi = true;
                        karakter.ziplamaSayisi = 0;
                        karakter.hizY = 0;
                        karakter.sinirlar.left += p.hizX * dt;
                    }
                }
            }

            for (auto& d : dusmanlar) {
                if (d.yasiyor && karakter.sinirlar.intersects(d.sinirlar)) {
                    if (karakter.hizY > 0 && karakter.sinirlar.top + karakter.sinirlar.height < d.sinirlar.top + 20.0f) {
                        d.yasiyor = false;
                        karakter.hizY = karakter.ziplamagucu * 0.8f;
                        skor += 20;
                    } else {
                        oyunBitti = true;
                        oyunBittiYazisi.setString("GAME OVER");
                        oyunBittiYazisi.setFillColor(sf::Color::Red);
                    }
                }
            }

            for (int y = 0; y < MAP_HEIGHT; y++) {
                for (int x = 0; x < MAP_WIDTH; x++) {
                    int blok = activeLevels[mevcutlevel][y][x];
                    sf::FloatRect blokSiniri(x * TILE_SIZE, y * TILE_SIZE, TILE_SIZE, TILE_SIZE);

                    if (blok == 2) {
                        sf::FloatRect altinSiniri(x * TILE_SIZE + 10, y * TILE_SIZE + 10, 20, 20);
                        if (karakter.sinirlar.intersects(altinSiniri)) {
                            activeLevels[mevcutlevel][y][x] = 0;
                            skor += 10;
                        }
                    } else if (blok == 3) {
                        if (karakter.sinirlar.intersects(blokSiniri)) {
                            oyunBitti = true;
                            oyunBittiYazisi.setString("GAME OVER");
                            oyunBittiYazisi.setFillColor(sf::Color::Red);
                        }
                    } else if (blok == 4) {
                        if (karakter.sinirlar.intersects(blokSiniri)) {
                            mevcutlevel++;

                            if (mevcutlevel >= MAX_LEVEL) {
                                oyunBitti = true;
                                oyunBittiYazisi.setString("CONGRATS");
                                oyunBittiYazisi.setFillColor(sf::Color::Green);
                            } else {
                                karakter.sinirlar.left = 50.0f;
                                karakter.sinirlar.top = 300.0f;
                                karakter.hizX = 0;
                                karakter.hizY = 0;
                                karakter.ziplamaSayisi = 0;
                                seviyeyiYukle();
                            }
                        }
                    }
                }
            }

            if (karakter.sinirlar.top > 600.0f || karakter.sinirlar.left < 0.0f || karakter.sinirlar.left > MAP_WIDTH * TILE_SIZE) {
                oyunBitti = true;
                oyunBittiYazisi.setString("GAME OVER");
                oyunBittiYazisi.setFillColor(sf::Color::Red);
            }
        }

        if (oyunBitti && sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
            oyunBitti = false;
            mevcutlevel = 0;
            skor = 0;
            karakter.sinirlar.left = 50.0f;
            karakter.sinirlar.top = 300.0f;
            karakter.hizX = 0;
            karakter.hizY = 0;
            karakter.ziplamaSayisi = 0;
            std::memcpy(activeLevels, levels, sizeof(levels));
            seviyeyiYukle();
        }

        float kameraX = karakter.sinirlar.left;

        if (kameraX < 400.0f)kameraX = 400.0f;
        if (kameraX > (MAP_WIDTH * TILE_SIZE) - 400.0f)kameraX = (MAP_WIDTH * TILE_SIZE) - 400.0f;

        kamera.setCenter(kameraX, 300.0f);
        pencere.setView(kamera);

        pencere.clear(sf::Color(135, 206, 235));

        if (arkaplanYuklendiMi) {
            float paralaksX = kamera.getCenter().x * 0.3f;
            arkaplanSprite.setTextureRect(sf::IntRect((int)paralaksX, 0, 800, 600));
            arkaplanSprite.setPosition(kamera.getCenter().x - 400.0f, 0.0f);
            pencere.draw(arkaplanSprite);
        }

        for (int y = 0; y < MAP_HEIGHT; y++) {
            for (int x = 0; x < MAP_WIDTH; x++) {
                int blok = activeLevels[mevcutlevel][y][x];

                if (blok == 1) {
                    zeminsekli.setFillColor(sf::Color(101, 67, 33));
                    zeminsekli.setPosition(x * TILE_SIZE, y * TILE_SIZE);
                    pencere.draw(zeminsekli);
                } else if (blok == 2) {
                    altintop.setPosition(x * TILE_SIZE + 10, y * TILE_SIZE + 10);
                    pencere.draw(altintop);
                } else if (blok == 3) {
                    zeminsekli.setFillColor(sf::Color::Red);
                    zeminsekli.setPosition(x * TILE_SIZE, y * TILE_SIZE);
                    pencere.draw(zeminsekli);
                } else if (blok == 4) {
                    zeminsekli.setFillColor(sf::Color::Green);
                    zeminsekli.setPosition(x * TILE_SIZE, y * TILE_SIZE);
                    pencere.draw(zeminsekli);
                }
            }
        }

        for (auto& d : dusmanlar) {
            if (d.yasiyor) {
                dusmanSekli.setPosition(d.sinirlar.left, d.sinirlar.top);
                pencere.draw(dusmanSekli);
            }
        }

        for (auto& p : platformlar) {
            platformSekli.setSize(sf::Vector2f(p.sinirlar.width, p.sinirlar.height));
            platformSekli.setPosition(p.sinirlar.left, p.sinirlar.top);
            pencere.draw(platformSekli);
        }

        for (auto& m : mermiler) {
            if (m.yasiyor) {
                mermiSekli.setPosition(m.sinirlar.left, m.sinirlar.top);
                pencere.draw(mermiSekli);
            }
        }

        if (karakter.gorselYuklendiMi) {
            karakter.sprite.setPosition(karakter.sinirlar.left, karakter.sinirlar.top);
            pencere.draw(karakter.sprite);
        }

        skoryazisi.setString("Skor: " + std::to_string(skor) + " | Level: " + std::to_string(mevcutlevel + 1));
        skoryazisi.setPosition(kamera.getCenter().x - 380.0f, 20.0f);
        pencere.draw(skoryazisi);

        if (oyunBitti) {
            yaziArkaplan.setPosition(kamera.getCenter().x - 375.0f, 185.0f);
            pencere.draw(yaziArkaplan);

            oyunBittiYazisi.setPosition(kamera.getCenter().x - 350.0f, 200.0f);
            pencere.draw(oyunBittiYazisi);

            restartYazisi.setPosition(kamera.getCenter().x - 220.0f, 260.0f);
            pencere.draw(restartYazisi);
        }
        pencere.display();
    }
    return 0;
}