#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <string>

const int TILE_SIZE = 40;
const int MAP_WIDTH = 20;
const int MAP_HEIGHT = 15;

int seviyeharitasi[MAP_HEIGHT][MAP_WIDTH] = {
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1},
    {1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,1,1,1,0,0,0,0,0,0,1,1,1,0,0,0,1},
    {1,1,1,1,1,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
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
            sprite.setTextureRect(sf::IntRect(0, 0, 525, 350));
        }
        else {
            std::cout << "ERROR: player.png bulunamadi!!!!!!!!" << std::endl;

        }
    }

    void guncelle(float dt) {
        hizX = 0.0f;

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            hizX = harekethizi;
            sagabakiyor = true;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
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
                    sprite.setTextureRect(sf::IntRect(mevcutKare * 525, 0, 525, 350));
                    zamanlayici = 0.0f;
                }
            }
            else {
                sprite.setTextureRect(sf::IntRect(0, 0, 525, 350));
            }
        }if (!sagabakiyor) {
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
    oyuncu karakter(50.0f, 300.0f);
    sf::RectangleShape zeminsekli(sf::Vector2f(TILE_SIZE, TILE_SIZE));
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
                if (seviyeharitasi[y][x] == 1) {
                    sf::FloatRect bloksiniri(x * TILE_SIZE, y * TILE_SIZE, TILE_SIZE, TILE_SIZE);
                    if (karakter.sinirlar.intersects(bloksiniri)) {
                        if (karakter.hizX > 0) {
                            karakter.sinirlar.left = bloksiniri.left - karakter.sinirlar.width;
                        }else if (karakter.hizX < 0) {
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
                if (seviyeharitasi[y][x] == 1) {
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
        pencere.clear(sf::Color(135, 206, 235));//gokyuzu mavisi

        for (int y = 0;y < MAP_HEIGHT; y++) {
            for (int x = 0;x < MAP_WIDTH; x++) {
                if (seviyeharitasi[y][x] == 1) {
                    zeminsekli.setFillColor(sf::Color(255, 165, 0));//turuncu zemin
                    zeminsekli.setPosition(x * TILE_SIZE, y * TILE_SIZE);
                    pencere.draw(zeminsekli);
                }
            }
        }
        if (karakter.gorselYuklendiMi) {
            karakter.sprite.setPosition(karakter.sinirlar.left, karakter.sinirlar.top);
            pencere.draw(karakter.sprite);
        }
        pencere.display();
    }
    return 0;
}
  