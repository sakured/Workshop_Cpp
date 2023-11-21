#include <sil/sil.hpp>
#include "random.hpp"

int main()
{
    // Choix de l'image à modifier
    sil::Image image{"images/logo.png"};

    // Exercice 1
    // for (glm::vec3 & color : image.pixels())
    // {
    //     color.r = 0.f;
    //     color.b = 0.f;
    // }
    // image.save("output/exo01.png");

    // Exercice 2
    // for (glm::vec3 & color : image.pixels())
    // {
    //     float stock {};
    //     stock = color.r;
    //     color.r = color.b;
    //     color.b = stock;
    // }
    // image.save("output/exo02.png");

    // Exercice 3
    // for (glm::vec3 & color : image.pixels())
    // {
    // float gris = (color.g + color.b + color.r) / 3;
    // color.r = gris;
    // color.g = gris;
    // color.b = gris;
    // }
    // image.save("output/exo03.png");

    // Exercice 4
    // for (glm::vec3 & color : image.pixels())
    // {
    //     color.r = 1 - color.r;
    //     color.g = 1 - color.g;
    //     color.b = 1 - color.b;
    // }
    // image.save("output/exo04.png");

    // Exercice 5
    // sil::Image degrade{300/*width*/, 200/*height*/};
    // float lumiere {0.0f};
    // for (int x{0}; x < degrade.height(); x++)
    // {
    //     for (int y{0}; y < degrade.width(); y++)
    //     {
    //         degrade.pixel(y, x).r += lumiere;
    //         degrade.pixel(y, x).g += lumiere;
    //         degrade.pixel(y, x).b += lumiere;
    //         lumiere += (1.0f / 300.0f);
    //     }
    //     lumiere = 0.0f;
    // }
    // degrade.save("output/exo05.png");

    // Exercice 6
    // float stock_r {};
    // float stock_g {};
    // float stock_b {};
    // for (int x{0}; x < image.width()/2; x++)
    // {
    //     for (int y{0}; y < image.height(); y++)
    //     {
    //         stock_r = image.pixel(x, y).r;
    //         stock_g = image.pixel(x, y).g;
    //         stock_b = image.pixel(x, y).b;

    //         image.pixel(x, y).r = image.pixel(image.width()-x-1, y).r;
    //         image.pixel(x, y).g = image.pixel(image.width()-x-1, y).g;
    //         image.pixel(x, y).b = image.pixel(image.width()-x-1, y).b;

    //         image.pixel(image.width()-x-1, y).r = stock_r;
    //         image.pixel(image.width()-x-1, y).g = stock_g;
    //         image.pixel(image.width()-x-1, y).b = stock_b;
    //     }
    // }
    // image.save("output/exo06.png");

    // Exercice 7
    // for (glm::vec3 & color : image.pixels())
    // {
    //     int rand {random_int(0, 4)};
    //     if (rand == 1) { // 1 chance sur 5 de brouiller mon pixel
    //         color.r = random_float(0.0f, 1.0f);
    //         color.g = random_float(0.0f, 1.0f);
    //         color.b = random_float(0.0f, 1.0f);
    //     }
    // }
    // image.save("output/exo07.png");

    // Exercice 8
    // sil::Image new_image{345/*width*/, 300/*height*/};
    // for (int x{0}; x < image.width(); x++)
    // {
    //     for (int y{0}; y < image.height(); y++)
    //     {
    //         new_image.pixel(image.height()-y-1, x).r = image.pixel(x, y).r;
    //         new_image.pixel(image.height()-y-1, x).g = image.pixel(x, y).g;
    //         new_image.pixel(image.height()-y-1, x).b = image.pixel(x, y).b;
    //     }
    // }
    // new_image.save("output/exo08.png");

    // Exercice 9
    // sil::Image new_image{300/*width*/, 345/*height*/};
    // for (int x{0}; x < image.width(); x++)
    // {
    //     for (int y{0}; y < image.height(); y++)
    //     {
    //         new_image.pixel(x, y).g = image.pixel(x, y).g;
    //         if (x-30 >=0) {
    //             new_image.pixel(x, y).r = image.pixel(x-30, y).r;
    //         }
    //         if (x+30 < image.width()) {
    //             new_image.pixel(x, y).b = image.pixel(x+30, y).b;
    //         }
    //     }
    // }
    // new_image.save("output/exo09.png");

    // Exercice 10
    // sil::Image photo{"images/photo.jpg"};
    // for (glm::vec3 & color : photo.pixels())
    // {
    //     // Moins de luminosite
    //     color.r = pow(color.r, 2.0f);
    //     color.g = pow(color.g, 2.0f);
    //     color.b = pow(color.b, 2.0f);
    // }
    // photo.save("output/exo10.jpg");
    // sil::Image photo_bis{"images/photo.jpg"};
    // for (glm::vec3 & color : photo_bis.pixels())
    // {
    //     // Plus de luminosite
    //     color.r = pow(color.r, 0.5f);
    //     color.g = pow(color.g, 0.5f);
    //     color.b = pow(color.b, 0.5f);
    // }
    // photo_bis.save("output/exo10_bis.jpg");

    // Exercice 11
    sil::Image disque{500/*width*/, 500/*height*/};
    for (int x{0}; x < disque.height(); x++)
    {
        for (int y{0}; y < disque.width(); y++)
        {
            if (pow (pow(x-255, 2.0f) + pow(y-255, 2.0f), 0.5f) < 100) {
                disque.pixel(y, x).r = 1.0f;
                disque.pixel(y, x).g = 1.0f;
                disque.pixel(y, x).b = 1.0f;
            }
        }
    }
    disque.save("output/exo11.png");

    // Exercice 12
    sil::Image cercle{500/*width*/, 500/*height*/};
    for (int x{0}; x < cercle.height(); x++)
    {
        for (int y{0}; y < cercle.width(); y++)
        {
            if ((pow (pow(x-255, 2.0f) + pow(y-255, 2.0f), 0.5f) < 100) && (pow (pow(x-255, 2.0f) + pow(y-255, 2.0f), 0.5f) > 90)) {
                cercle.pixel(y, x).r = 1.0f;
                cercle.pixel(y, x).g = 1.0f;
                cercle.pixel(y, x).b = 1.0f;
            }
        }
    }
    cercle.save("output/exo12.png");
}