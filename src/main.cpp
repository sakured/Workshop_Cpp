#define _USE_MATH_DEFINES
#include <glm/gtx/matrix_transform_2d.hpp>
#include <sil/sil.hpp>
#include <iostream>
#include "random.hpp"
#include <math.h>
#include <cmath>
#include <complex>
#include <glm/gtx/matrix_transform_2d.hpp>

glm::vec2 rotated(glm::vec2 point, glm::vec2 center_of_rotation, float angle)
{
    return glm::vec2{glm::rotate(glm::mat3{1.f}, angle) * glm::vec3{point - center_of_rotation, 0.f}} + center_of_rotation;
} 

int main()
 {
    float pi {M_PI};

    // Choix de l'image à modifier
    sil::Image image{"images/logo.png"};

    // // Exercice 1
    // for (glm::vec3 & color : image.pixels())
    // {
    //     color.r = 0.f;
    //     color.b = 0.f;
    // }
    // image.save("output/exo01.png");

    // // Exercice 2
    // for (glm::vec3 & color : image.pixels())
    // {
    //     float stock {};
    //     stock = color.r;
    //     color.r = color.b;
    //     color.b = stock;
    // }
    // image.save("output/exo02.png");

    // // Exercice 3
    // for (glm::vec3 & color : image.pixels())
    // {
    // float gris = (color.g + color.b + color.r) / 3;
    // color.r = gris;
    // color.g = gris;
    // color.b = gris;
    // }
    // image.save("output/exo03.png");

    // // Exercice 4
    // for (glm::vec3 & color : image.pixels())
    // {
    //     color.r = 1 - color.r;
    //     color.g = 1 - color.g;
    //     color.b = 1 - color.b;
    // }
    // image.save("output/exo04.png");

    // // Exercice 5
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

    // // Exercice 6
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

    // // Exercice 7
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

    // // Exercice 8
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

    // // Exercice 9
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

    // // Exercice 10
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

    // // Exercice 11
    // sil::Image disque{500/*width*/, 500/*height*/};
    // for (int x{0}; x < disque.height(); x++)
    // {
    //     for (int y{0}; y < disque.width(); y++)
    //     {
    //         if (pow (pow(x-255, 2.0f) + pow(y-255, 2.0f), 0.5f) < 100) {
    //             disque.pixel(y, x).r = 1.0f;
    //             disque.pixel(y, x).g = 1.0f;
    //             disque.pixel(y, x).b = 1.0f;
    //         }
    //     }
    // }
    // disque.save("output/exo11.png");

    // // Exercice 12
    // sil::Image cercle{500/*width*/, 500/*height*/};
    // for (int x{0}; x < cercle.height(); x++)
    // {
    //     for (int y{0}; y < cercle.width(); y++)
    //     {
    //         if ((pow (pow(x-255, 2.0f) + pow(y-255, 2.0f), 0.5f) < 100) && (pow (pow(x-255, 2.0f) + pow(y-255, 2.0f), 0.5f) > 90)) {
    //             cercle.pixel(y, x).r = 1.0f;
    //             cercle.pixel(y, x).g = 1.0f;
    //             cercle.pixel(y, x).b = 1.0f;
    //         }
    //     }
    // }
    // cercle.save("output/exo12.png");


    //// Exercice 13 :
    // sil::Image rosace{500/*width*/, 500/*height*/};
    // for (int x{0}; x < rosace.height(); x++) //premiere boucle for pour cercle du centre
    // {
    //     for (int y{0}; y < rosace.width(); y++)
    //     {
    //         if ((pow (pow(x-255, 2.0f) + pow(y-255, 2.0f), 0.5f) < 100) && (pow (pow(x-255, 2.0f) + pow(y-255, 2.0f), 0.5f) > 95)) {
    //             rosace.pixel(y, x).r = 1.0f;
    //             rosace.pixel(y, x).g = 1.0f;
    //             rosace.pixel(y, x).b = 1.0f;
    //         }
    //     }
    // } 
    // for (int i {}; i<6 ; ++i) // deuxieme boucle pour les autres cercles 
    // {
    //     int x_centre = cos(i*pi/3)*100+255 ;
    //     int y_centre = sin(i*pi/3)*100+255 ;
    //     for (int x{0}; x < rosace.height(); x++)
    //     {
    //         for (int y{0}; y < rosace.width(); y++)
    //         {
    //             if ((pow (pow(x-x_centre, 2.0f) + pow(y-y_centre, 2.0f), 0.5f) < 100) && (pow (pow(x-x_centre, 2.0f) + pow(y-y_centre, 2.0f), 0.5f) > 95)) {
    //                 rosace.pixel(y, x).r = 1.0f;
    //                 rosace.pixel(y, x).g = 1.0f;
    //                 rosace.pixel(y, x).b = 1.0f;
    //             }
    //         }
    //     }
    // }
    // rosace.save("output/exo13.png");

    // // Exercice 14
    // sil::Image new_image{345*6/*width*/, 300*6/*height*/};
    // for (int i=0; i<5; i++) 
    // {
    //     for (int j=0; j<5; j++) 
    //     {
    //         for (int x{0}; x < image.width(); x++)
    //         {
    //             for (int y{0}; y < image.height(); y++)
    //             {
    //                 new_image.pixel(i*300+x, j*345+y).r = image.pixel(x, y).r;
    //                 new_image.pixel(i*300+x, j*345+y).g = image.pixel(x, y).g;
    //                 new_image.pixel(i*300+x, j*345+y).b = image.pixel(x, y).b;
    //             }
    //         }
    //     }
    // }
    // new_image.save("output/exo14.png");

    // // Exercice 15
    // sil::Image new_image{345*6/*width*/, 300*6/*height*/};
    // int x_direction {};
    // int y_direction {};
    // for (int i=0; i<5; i++) 
    // {
    //     for (int j=0; j<5; j++) 
    //     {
    //         for (int x{0}; x < image.width(); x++)
    //         {
    //             for (int y{0}; y < image.height(); y++)
    //             {
    //                 // Choix d'une symétrie verticale ou non
    //                 if (i%2 == 1) {
    //                     x_direction = image.width()-x-1;
    //                 } else {
    //                     x_direction = x;
    //                 }
    //                 // Choix d'une symétrie horizontale ou non
    //                 if (j%2 == 1) {
    //                     y_direction = image.height()-y-1;
    //                 } else {
    //                     y_direction = y;
    //                 }

    //                 // Affichage de l'image
    //                 new_image.pixel(i*300+x, j*345+y).r = image.pixel(x_direction, y_direction).r;
    //                 new_image.pixel(i*300+x, j*345+y).g = image.pixel(x_direction, y_direction).g;
    //                 new_image.pixel(i*300+x, j*345+y).b = image.pixel(x_direction, y_direction).b;
    //             }
    //         }
    //     }
    // }
    // new_image.save("output/exo15.png");

    // // Exercice 16 
    // for (glm::vec3 & color : image.pixels())
    // {
    //     int rand {random_int(0, 1000)};// 1 chance sur 1000 de faire un glitch
    //     int rand_x1 {random_int(1, 60)};// largeur aléatoire 
    //     int rand_y1 {random_int(1, 10)};// hauteur aléatoire
    //     int rand_x2 {random_int(rand_x1,300)};// position x du pixel avec lequel on a interverti
    //     int rand_y2 {random_int(rand_y1,345)};// position y du pixel avec lequel on a interverti
    //     if (rand == 1)
    //     {
    //         for (int x{0}; x < rand_x1; x++)
    //         {
    //             for (int y{0}; y < rand_y1; y++)
    //             {
    //                 std::swap(image.pixel(x, y).r, image.pixel((x+rand_x2)%image.width(), (y+rand_y2)%image.height()).r);// modulo pour eviter de sortir de l'image
    //                 std::swap(image.pixel(x, y).g, image.pixel((x+rand_x2)%image.width(), (y+rand_y2)%image.height()).g);
    //                 std::swap(image.pixel(x, y).b, image.pixel((x+rand_x2)%image.width(), (y+rand_y2)%image.height()).b);
    //             }
    //         }
    //     }
    // }
    // image.save("output/exo16.png");

//     // Exercice 17
//     sil::Image fractale{500/*width*/, 500/*height*/};
//     int compteur {};
//     for (float x{-2.5f}; x < 2.5f; x+=0.01f)
//     //     int rand {random_int(0, 1000)};// 1 chance sur 1000 de faire un glitch
//     {
//         for (float y{-2.5f}; y < 2.5f; y+=0.01f)
//         {
//             std::complex<float> c {x,y};
//             std::complex<float> z {0.0f, 0.0f};
//             // Calcul du nombre d'itérations nécésaires à ce que abs(z) dépasse 2
//             for (int i{0}; i<50; i++) {
//                 z = (z * z) + c;
//                 if (std::abs(z) >= 2.f) {
//                     compteur = i;
//                     break;
//                 }
//             }
//             // Cas où abs(z) est toujours inférieur à 2
//             if (std::abs(z) < 2.f) {
//                 compteur = 50;
//             } 
//             // Coloriage des pixel 
//             fractale.pixel(x*100+250,y*100+250).r = 0.0f + static_cast<float>(compteur)/50.0f;
//             fractale.pixel(x*100+250,y*100+250).g = 0.0f + static_cast<float>(compteur)/50.0f;
//             fractale.pixel(x*100+250,y*100+250).b = 0.0f + static_cast<float>(compteur)/50.0f;
//         }
//     }
//     fractale.save("output/exo17.png");

//    // Exercice 18
//     sil::Image vortex{300/*width*/, 345/*height*/};
//     for (int x{ }; x < image.width(); x++)
//     {
//         for (int y{0}; y < image.height(); y++)
//         {
//             glm::vec2 point{x, y};
//             glm::vec2 center_of_rotation{image.width()/2, image.height()/2};

//             glm::vec2 new_point{ rotated(point ,center_of_rotation ,pow((pow((x-image.width()/2),2)+pow((y-image.height()/2),2)),0.5)/10) };

//             if(new_point.y<vortex.height() && new_point.x<vortex.width() && new_point.y>0 && new_point.x>0) // TODO vérifier que on est bien dans l'image
//             {
//                 vortex.pixel(x, y) = image.pixel(new_point.x, new_point.y);
//             }
//         }
//     } 
//     vortex.save("output/exo18.png"); 

    // Exercice 19
    sil::Image photo{"images/photo.jpg"};
    for (int x{0}; x < photo.width(); x++)
    {
        for (int y{0}; y < photo.height(); y++)
        {   
            float proba_blanc = (photo.pixel(x,y).r + photo.pixel(x,y).g + photo.pixel(x,y).b) / 3.f;
            if (random_float(0.f, 1.f) < proba_blanc) {
                photo.pixel(x, y) = glm::vec3{1};
            } else {
                photo.pixel(x, y) = glm::vec3{0};
            }
        }
    } 
    photo.save("output/exo19.jpg"); 

    // Exercice 20
    sil::Image low_image{"images/photo_faible_contraste.jpg"};
    float min {1.f}; // Plus petite luminosité
    float max {0.f}; // Plus grande luminosité

    for (int x{0}; x < image.width(); x++)
    {
        for (int y{0}; y < image.height(); y++)
        {   
            // On cherche le pixel avec le moins de lumière
            if ((low_image.pixel(x,y).r + low_image.pixel(x,y).g + low_image.pixel(x,y).b)/3.f < min) {
                min = (low_image.pixel(x,y).r + low_image.pixel(x,y).g + low_image.pixel(x,y).b)/3.f;
            }
            // On cherche le pixel avec le plus de lumière
            if ((low_image.pixel(x,y).r + low_image.pixel(x,y).g + low_image.pixel(x,y).b)/3.f > max) {
                max = (low_image.pixel(x,y).r + low_image.pixel(x,y).g + low_image.pixel(x,y).b)/3.f;
            }
        }
    } 

    // Action sur les pixels
    for (int x{0}; x < low_image.width(); x++)
    {
        for (int y{0}; y < low_image.height(); y++)
        {   
            low_image.pixel(x,y).r -= min;
            low_image.pixel(x,y).g -= min;
            low_image.pixel(x,y).b -= min;
            
            low_image.pixel(x,y).r *= 1.f / max;
            low_image.pixel(x,y).g *= 1.f / max;
            low_image.pixel(x,y).b *= 1.f / max;
        }
    } 
    low_image.save("output/exo20.jpg"); 

}  

