#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <string>

const int TILE_SIZE = 40;
const int MAP_WIDTH = 40;
const int MAP_HEIGHT = 15;
const int MAX_LEVEL = 3;

int mevcutlevel = 0;

int levels[MAX_LEVEL][MAP_HEIGHT][MAP_WIDTH] = {
    //LEVEL 1
    {
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
        {1,0,0,0,0,2,1,1,1,1,0,0,0,0,0,0,0,0,0,1, 1,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,4},
        {1,0,0,0,1,1,1,0,0,0,0,0,0,1,1,1,0,0,0,1, 1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,4},
        {1,1,1,1,1,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1, 1,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1},
        {1,1,1,1,1,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1, 1,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1},
        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
    },
    //LEVEL 2
    {
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,2, 2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1, 1,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,2,2,0,0,0,0,0,0,0,0,0,0,0,0, 0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0},
        {1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0},
        {1,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
        {1,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,1,1,1,0, 0,0,1,1,0,0,0,1,1,1,0,0,0,1,1,1,0,0,0,4},
        {1,1,1,1,1,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3, 3,3,3,3,3,3,3,3,3,3,3,3,3,1,1,1,1,1,1,1},
        {1,1,1,1,1,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3, 3,3,3,3,3,3,3,3,3,3,3,3,3,1,1,1,1,1,1,1},
        {1,1,1,1,1,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3, 3,3,3,3,3,3,3,3,3,3,3,3,3,1,1,1,1,1,1,1}
    },
    //LEVEL 3
    {
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1, 0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,2,0,0,0,0,0,1,1,1,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0, 0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {1,1,0,0,0,1,1,1,0,0,0,0,0,0,0,2,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,4},
        {1,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1, 0,0,0,1,0,0,0,0,0,0,1,1,1,0,0,0,1,1,1,4},
        {1,1,3,3,1,3,3,3,3,3,1,3,3,3,3,3,3,3,3,1, 3,3,3,1,3,3,3,3,3,3,3,3,3,3,3,3,1,1,1,1},
        {1,1,3,3,1,3,3,3,3,3,1,3,3,3,3,3,3,3,3,1, 3,3,3,1,3,3,3,3,3,3,3,3,3,3,3,3,1,1,1,1},
        {1,1,3,3,1,3,3,3,3,3,1,3,3,3,3,3,3,3,3,1, 3,3,3,1,3,3,3,3,3,3,3,3,3,3,3,3,1,1,1,1}
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

    oyuncu(float baslangicX, float baslangicY) {
        sinirlar = sf::FloatRect(baslangicX, baslangicY, 30.0f, 30.0f);

        if (doku.loadFromFile("player.png")) {
            gorselYuklendiMi = true;
            sprite.setTexture(doku);
            sprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
        }else {
            std::cout << "ERROR: player.png bulunamadi!!!!!!!!" << std::endl;
        }
    }

    void guncelle(float dt) {
        hizX = 0.0f;

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            hizX = harekethizi;
            sagabakiyor = true;
        }else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            hizX = -harekethizi;
            sagabakiyor = false;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && yerdemi) {
            hizY = ziplamagucu;
            yerdemi = false;
        }

        hizY += yercekimi * dt;

        if (gorselYuklendiMi) {
            zamanlayici += dt;
            if (hizX != 0.0f) {
                if (zamanlayici > 0.1f) {
                    mevcutKare = (mevcutKare + 1) % 4;
                    sprite.setTextureRect(sf::IntRect(mevcutKare * 32, 0, 32, 32));
                    zamanlayici = 0.0f;
                }
            }
            else {
                sprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
            }
        }

        if (!sagabakiyor) {
            sprite.setScale(-1.0f, 1.0f);
            sprite.setOrigin(32.0f, 0.0f);
        }
        else {
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

    sf::CircleShape altintop(10.0f);
    altintop.setFillColor(sf::Color::Yellow);
    int skor = 0;

    sf::Font font;
    if (!font.loadFromFile("CENTURY.ttf")) {
        std::cout << "ERROR: dosya bulunamadi!" << std::endl;
    }
    sf::Text skoryazisi;
    skoryazisi.setFont(font);
    skoryazisi.setCharacterSize(24);
    skoryazisi.setFillColor(sf::Color::White);

    while (pencere.isOpen()) {
        float dt = saat.restart().asSeconds();
        sf::Event olay;
        while (pencere.pollEvent(olay)) {
            if (olay.type == sf::Event::Closed) {
                pencere.close();
            }
        }

        karakter.guncelle(dt);

        karakter.sinirlar.left += karakter.hizX * dt;
        for (int y = 0;y < MAP_HEIGHT;y++) {
            for (int x = 0;x < MAP_WIDTH;x++) {
                if (levels[mevcutlevel][y][x] == 1) {
                    sf::FloatRect bloksiniri(x * TILE_SIZE, y * TILE_SIZE, TILE_SIZE, TILE_SIZE);
                    if (karakter.sinirlar.intersects(bloksiniri)) {
                        if (karakter.hizX > 0) {
                            karakter.sinirlar.left = bloksiniri.left - karakter.sinirlar.width;
                        }
                        else if (karakter.hizX < 0) {
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
                if (levels[mevcutlevel][y][x] == 1) {
                    sf::FloatRect bloksiniri(x * TILE_SIZE, y * TILE_SIZE, TILE_SIZE, TILE_SIZE);
                    if (karakter.sinirlar.intersects(bloksiniri)) {
                        if (karakter.hizY > 0) {
                            karakter.sinirlar.top = bloksiniri.top - karakter.sinirlar.height;
                            karakter.yerdemi = true;
                        }
                        else if (karakter.hizY < 0) {
                            karakter.sinirlar.top = bloksiniri.top + bloksiniri.height;
                        }
                        karakter.hizY = 0;
                    }
                }
            }
        }
        for (int y = 0; y < MAP_HEIGHT; y++) {
            for (int x = 0; x < MAP_WIDTH; x++) {
                int blok = levels[mevcutlevel][y][x];
                sf::FloatRect blokSiniri(x * TILE_SIZE, y * TILE_SIZE, TILE_SIZE, TILE_SIZE);

                if (blok == 2) {
                    sf::FloatRect altinSiniri(x * TILE_SIZE + 10, y * TILE_SIZE + 10, 20, 20);
                    if (karakter.sinirlar.intersects(altinSiniri)) {
                        levels[mevcutlevel][y][x] = 0;
                        skor += 10;
                    }
                }
                else if (blok == 4) { 
                    if (karakter.sinirlar.intersects(blokSiniri)) {
                        mevcutlevel++;

                        if (mevcutlevel >= MAX_LEVEL) {
                            mevcutlevel = 0;
                        }

                        karakter.sinirlar.left = 50.0f;
                        karakter.sinirlar.top = 300.0f;
                        karakter.hizX = 0;
                        karakter.hizY = 0;
                    }
                }
            }
        }

        float kameraX = karakter.sinirlar.left;

        if (kameraX < 400.0f)kameraX = 400.0f;
        if (kameraX > (MAP_WIDTH * TILE_SIZE) - 400.0f)kameraX = (MAP_WIDTH * TILE_SIZE) - 400.0f;

        kamera.setCenter(kameraX, 300.0f);
        pencere.setView(kamera);

        pencere.clear(sf::Color(135, 206, 235));

        for (int y = 0; y < MAP_HEIGHT; y++) {
            for (int x = 0; x < MAP_WIDTH; x++) {
                int blok = levels[mevcutlevel][y][x];

                if (blok == 1) {//kahverengi
                    zeminsekli.setFillColor(sf::Color(101, 67, 33));
                    zeminsekli.setPosition(x * TILE_SIZE, y * TILE_SIZE);
                    pencere.draw(zeminsekli);
                }
                else if (blok == 2) {//sari
                    altintop.setPosition(x * TILE_SIZE + 10, y * TILE_SIZE + 10);
                    pencere.draw(altintop);
                }else if (blok == 3) {//kirmizi
                    zeminsekli.setFillColor(sf::Color::Red);
                    zeminsekli.setPosition(x * TILE_SIZE, y * TILE_SIZE);
                    pencere.draw(zeminsekli);
                }else if (blok == 4) {//yesil
                    zeminsekli.setFillColor(sf::Color::Green);
                    zeminsekli.setPosition(x * TILE_SIZE, y * TILE_SIZE);
                    pencere.draw(zeminsekli);
                }
            }
        }

        if (karakter.gorselYuklendiMi) {
            karakter.sprite.setPosition(karakter.sinirlar.left, karakter.sinirlar.top);
            pencere.draw(karakter.sprite);
        }

        skoryazisi.setString("Skor: " + std::to_string(skor) + " | Level: " + std::to_string(mevcutlevel + 1));
        skoryazisi.setPosition(kamera.getCenter().x - 380.0f, 20.0f);
        pencere.draw(skoryazisi);

        pencere.display();
    }
    return 0;
}