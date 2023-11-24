#define _USE_MATH_DEFINES
#include <glm/gtx/matrix_transform_2d.hpp>
#include <sil/sil.hpp>
#include <iostream>
#include "random.hpp"
#include <math.h>
#include <cmath>
#include <complex>
#include <algorithm>
#include <vector>
#include <glm/gtx/matrix_transform_2d.hpp>
#include "utils.hpp"

/**
 * Fonction main
 */
int main()
 {
    // Initialisation de pi
    float pi {M_PI};

    // Choix de l'image à modifier
    sil::Image image{"images/logo.png"};
    sil::Image photo{"images/photo.jpg"};
    sil::Image photo_low_contrast{"images/photo_faible_contraste.jpg"};

    // Utilisation des fonctions sur les images
    greenOnly(image);
    changeColors(image);
    blackAndWhite(image);
    negative(image);
    gradient();
    mirror(image);
    noise(image);
    rotation(image);
    rgbSplit(image);
    lessAndMoreLight(photo, photo);
    disk();
    circle();
    rosace();
    mosaic(image);
    mirrorMosaic(image);
    glitch(image);
    fractale();
    vortex(image);
    dithering(photo);
    betterContrast(photo_low_contrast);
    blur(image, 10);
    applyKernel({{-1.f, -1.f, -1.f},{-1.f, 8.f, -1.f},{-1.f, -1.f, -1.f}}, image, "outline"); // outline
    applyKernel({{-2.f, -1.f, 0.f}, {-1.f, 1.f, 1.f}, {0.f, 1.f, 2.f}}, image, "emboss"); // emboss
    applyKernel({{0.f, -1.f, -0.f}, {-1.f, 5.f, -1.f}, {0.f, -1.f, 0.f}}, image, "sharpen"); // sharpen
    differenceOfGaussians(photo);
    sortPixels(image);

    return 0;
 }

 /**
 * Fait une rotation d'une image d'un angle donné autour d'un point de coordonnées données
 */
glm::vec2 rotated(glm::vec2 point, glm::vec2 center_of_rotation, float angle)
{
    return glm::vec2{glm::rotate(glm::mat3{1.f}, angle) * glm::vec3{point - center_of_rotation, 0.f}} + center_of_rotation;
} 

 /**
 * Renvoie la luminosité d'un pixel
 */
float brightness(glm::vec3 color)
{
    return (color.r + color.g + color.b) / 3.f;
} 

 /**
 * Ne garde que le vert d'une image
 */
void greenOnly(sil::Image image) {
    for (glm::vec3 & color : image.pixels())
    {
        color.r = 0.f;
        color.b = 0.f;
    }
    image.save("output/greenOnly.png");
}

 /**
 * Change les canaux d'une image
 */
void changeColors(sil::Image image) {
    for (glm::vec3 & color : image.pixels())
    {
        float stock {};
        stock = color.r;
        color.r = color.b;
        color.b = stock;
    }
    image.save("output/changeColors.png");
}

 /**
 * Passe une image en noir et blanc
 */
void blackAndWhite(sil::Image image) {
    for (glm::vec3 & color : image.pixels())
    {
        float gray = (color.g + color.b + color.r) / 3.f;
        color.r = gray;
        color.g = gray;
        color.b = gray;
    }
    image.save("output/blackAndWhite.png");
}

 /**
 * Passe une image en négatif
 */
void negative(sil::Image image) {
    for (glm::vec3 & color : image.pixels())
    {
        color.r = 1 - color.r;
        color.g = 1 - color.g;
        color.b = 1 - color.b;
    }
    image.save("output/negative.png");
}

 /**
 * Crée un dégradé noir et blanc horizontal
 */
void gradient() {
    sil::Image gradient{300, 200};
    float light {0.f};
    for (int x{0}; x < gradient.height(); x++)
    {
        for (int y{0}; y < gradient.width(); y++)
        {
            gradient.pixel(y, x).r += light;
            gradient.pixel(y, x).g += light;
            gradient.pixel(y, x).b += light;
            light += (1.f / 300.f);
        }
        light = 0.f;
    }
    gradient.save("output/gradient.png");
}

 /**
 * Fait une symétrie verticale d'une image
 */
void mirror(sil::Image image) {
    float stock_r {};
    float stock_g {};
    float stock_b {};
    for (int x{0}; x < image.width()/2; x++)
    {
        for (int y{0}; y < image.height(); y++)
        {
            // On stocke les couleurs des pixels à gauche de notre axe de symétrie
            stock_r = image.pixel(x, y).r;
            stock_g = image.pixel(x, y).g;
            stock_b = image.pixel(x, y).b;

            // On attribue la couleurs des pixels à droite de note axe de symétrie aux pixels à gauche de notre axe de symétrie
            image.pixel(x, y).r = image.pixel(image.width()-x-1, y).r;
            image.pixel(x, y).g = image.pixel(image.width()-x-1, y).g;
            image.pixel(x, y).b = image.pixel(image.width()-x-1, y).b;

            // On attribue l'ancienne couleur (maintenant stokée) des pixels à gauche de note axe de symétrie aux pixels à gauche de notre axe
            image.pixel(image.width()-x-1, y).r = stock_r;
            image.pixel(image.width()-x-1, y).g = stock_g;
            image.pixel(image.width()-x-1, y).b = stock_b;
        }
    }
    image.save("output/miror.png");
}

 /**
 * Ajoute du bruit sur une image
 */
void noise(sil::Image image) {
    for (glm::vec3 & color : image.pixels())
    {
        int rand {random_int(0, 4)};
        if (rand == 1) { // 1 chance sur 5 de brouiller mon pixel
            color.r = random_float(0.0f, 1.0f);
            color.g = random_float(0.0f, 1.0f);
            color.b = random_float(0.0f, 1.0f);
        }
    }
    image.save("output/noise.png");
}

 /**
 * Applique une rotation à 90° de l'image
 */
void rotation(sil::Image image) {
    sil::Image new_image{image.height(), image.width()};
    for (int x{0}; x < image.width(); x++)
    {
        for (int y{0}; y < image.height(); y++)
        {
            new_image.pixel(image.height()-y-1, x).r = image.pixel(x, y).r;
            new_image.pixel(image.height()-y-1, x).g = image.pixel(x, y).g;
            new_image.pixel(image.height()-y-1, x).b = image.pixel(x, y).b;
        }
    }
    new_image.save("output/rotation.png");
}

 /**
 * Split le rouge, le bleu et le vert d'une image
 */
void rgbSplit(sil::Image image) {
    sil::Image new_image {image.width(), image.height()};
    for (int x{0}; x < image.width(); x++)
    {
        for (int y{0}; y < image.height(); y++)
        {
            new_image.pixel(x, y).g = image.pixel(x, y).g;
            // On gère le rouge
            if (x-30 >=0) {
                new_image.pixel(x, y).r = image.pixel(x-30, y).r;
            }
            // On gère le bleu
            if (x+30 < image.width()) {
                new_image.pixel(x, y).b = image.pixel(x+30, y).b;
            }
        }
    }
    new_image.save("output/rgbSplit.png");
}

 /**
 * Crée une copie plus lumineuse et une copie plus sombre d'une image
 */
void lessAndMoreLight(sil::Image image, sil::Image image_bis) {
    // Moins de luminosite
    for (glm::vec3 & color : image.pixels())
    {
        color.r = pow(color.r, 2.0f);
        color.g = pow(color.g, 2.0f);
        color.b = pow(color.b, 2.0f);
    }
    image.save("output/lessLight.jpg");
    // Plus de luminosite
    for (glm::vec3 & color : image_bis.pixels())
    {
        color.r = pow(color.r, 0.5f);
        color.g = pow(color.g, 0.5f);
        color.b = pow(color.b, 0.5f);
    }
    image_bis.save("output/moreLight.jpg");
}

 /**
 * Crée un disque blanc
 */
void disk() {
    sil::Image disk {500, 500};
    for (int x{0}; x < disk.height(); x++)
    {
        for (int y{0}; y < disk.width(); y++)
        {
            if (pow (pow(x-255, 2.0f) + pow(y-255, 2.0f), 0.5f) < 100) {
                disk.pixel(y, x).r = 1.0f;
                disk.pixel(y, x).g = 1.0f;
                disk.pixel(y, x).b = 1.0f;
            }
        }
    }
    disk.save("output/disk.png");
}

 /**
 * Crée un cercle blanc
 */
void circle() {
    sil::Image circle {500, 500};
    for (int x{0}; x < circle.height(); x++)
    {
        for (int y{0}; y < circle.width(); y++)
        {
            if ((pow (pow(x-255, 2.0f) + pow(y-255, 2.0f), 0.5f) < 100) && (pow (pow(x-255, 2.0f) + pow(y-255, 2.0f), 0.5f) > 90)) {
                circle.pixel(y, x).r = 1.0f;
                circle.pixel(y, x).g = 1.0f;
                circle.pixel(y, x).b = 1.0f;
            }
        }
    }
    circle.save("output/circle.png");
}

 /**
 * Crée une rosace
 */
void rosace() {
    sil::Image rosace {500, 500};
    // Premiere boucle for pour cercle du centre
    for (int x{0}; x < rosace.height(); x++) 
    {
        for (int y{0}; y < rosace.width(); y++)
        {
            if ((pow (pow(x-255, 2.0f) + pow(y-255, 2.0f), 0.5f) < 100) && (pow (pow(x-255, 2.0f) + pow(y-255, 2.0f), 0.5f) > 95)) {
                rosace.pixel(y, x).r = 1.0f;
                rosace.pixel(y, x).g = 1.0f;
                rosace.pixel(y, x).b = 1.0f;
            }
        }
    } 
    // Deuxieme boucle pour les autres cercles 
    for (int i {}; i<6 ; ++i) 
    {
        int x_centre = cos(i*M_PI/3)*100+255 ;
        int y_centre = sin(i*M_PI/3)*100+255 ;
        for (int x{0}; x < rosace.height(); x++)
        {
            for (int y{0}; y < rosace.width(); y++)
            {
                if ((pow (pow(x-x_centre, 2.0f) + pow(y-y_centre, 2.0f), 0.5f) < 100) && (pow (pow(x-x_centre, 2.0f) + pow(y-y_centre, 2.0f), 0.5f) > 95)) {
                    rosace.pixel(y, x).r = 1.0f;
                    rosace.pixel(y, x).g = 1.0f;
                    rosace.pixel(y, x).b = 1.0f;
                }
            }
        }
    }
    rosace.save("output/rosace.png");
}

/**
 * Crée une mosaïque
 */
void mosaic(sil::Image image) {
    sil::Image new_image {image.width()*5, image.height()*5};
    for (int i=0; i<5; i++) 
    {
        for (int j=0; j<5; j++) 
        {
            for (int x{0}; x < image.width(); x++)
            {
                for (int y{0}; y < image.height(); y++)
                {
                    new_image.pixel(i*300+x, j*345+y).r = image.pixel(x, y).r;
                    new_image.pixel(i*300+x, j*345+y).g = image.pixel(x, y).g;
                    new_image.pixel(i*300+x, j*345+y).b = image.pixel(x, y).b;
                }
            }
        }
    }
    new_image.save("output/mosaic.png");
}

 /**
 * Crée une mosaïque mirroir
 */
void mirrorMosaic(sil::Image image) {
    sil::Image new_image {image.width()*5, image.height()*5};
    int x_direction {};
    int y_direction {};
    for (int i=0; i<5; i++) 
    {
        for (int j=0; j<5; j++) 
        {
            for (int x{0}; x < image.width(); x++)
            {
                for (int y{0}; y < image.height(); y++)
                {
                    // Choix d'une symétrie verticale ou non
                    if (i%2 == 1) {
                        x_direction = image.width()-x-1;
                    } else {
                        x_direction = x;
                    }
                    // Choix d'une symétrie horizontale ou non
                    if (j%2 == 1) {
                        y_direction = image.height()-y-1;
                    } else {
                        y_direction = y;
                    }

                    // Affichage de l'image
                    new_image.pixel(i*300+x, j*345+y).r = image.pixel(x_direction, y_direction).r;
                    new_image.pixel(i*300+x, j*345+y).g = image.pixel(x_direction, y_direction).g;
                    new_image.pixel(i*300+x, j*345+y).b = image.pixel(x_direction, y_direction).b;
                }
            }
        }
    }
    new_image.save("output/mirrorMosaic.png");
}

 /**
 * Fait un glitch sur une image
 */
void glitch(sil::Image image) {
    for (glm::vec3 & color : image.pixels())
    {
        int rand {random_int(0, 1000)}; // 1 chance sur 1000 de faire un glitch
        int rand_x1 {random_int(1, 60)}; // largeur aléatoire 
        int rand_y1 {random_int(1, 10)}; // hauteur aléatoire
        int rand_x2 {random_int(rand_x1,300)}; // position x du pixel avec lequel on a interverti
        int rand_y2 {random_int(rand_y1,345)}; // position y du pixel avec lequel on a interverti

        // On effectue le glitch
        if (rand == 1) {
            for (int x{0}; x < rand_x1; x++)
            {
                for (int y{0}; y < rand_y1; y++)
                {
                    std::swap(image.pixel(x, y).r, image.pixel((x+rand_x2)%image.width(), (y+rand_y2)%image.height()).r); // modulo pour eviter de sortir de l'image
                    std::swap(image.pixel(x, y).g, image.pixel((x+rand_x2)%image.width(), (y+rand_y2)%image.height()).g);
                    std::swap(image.pixel(x, y).b, image.pixel((x+rand_x2)%image.width(), (y+rand_y2)%image.height()).b);
                }
            }
        }
    }
    image.save("output/glitch.png");
}

 /**
 * Crée la fractale de Mandelbrot
 */
void fractale() {
    sil::Image fractale{500, 500};
    int counter {};
    for (float x{-2.5f}; x < 2.5f; x+=0.01f)
    {
        for (float y{-2.5f}; y < 2.5f; y+=0.01f)
        {
            std::complex<float> c {x,y};
            std::complex<float> z {0.0f, 0.0f};
            // Calcul du nombre d'itérations nécésaires à ce que abs(z) dépasse 2
            for (int i{0}; i<50; i++) {
                z = (z * z) + c;
                if (std::abs(z) >= 2.f) {
                    counter = i;
                    break;
                }
            }
            // Cas où abs(z) est toujours inférieur à 2
            if (std::abs(z) < 2.f) {
                counter = 50;
            } 
            // Coloriage des pixel 
            fractale.pixel(x*100+250,y*100+250).r = 0.0f + static_cast<float>(counter)/50.0f;
            fractale.pixel(x*100+250,y*100+250).g = 0.0f + static_cast<float>(counter)/50.0f;
            fractale.pixel(x*100+250,y*100+250).b = 0.0f + static_cast<float>(counter)/50.0f;
        }
    }
    fractale.save("output/fractale.png");
}

 /**
 * Crée un vortex à partir d'une image
 */
void vortex(sil::Image image) {
    sil::Image vortex {image.width(), image.height()};
    for (int x{ }; x < image.width(); x++)
    {
        for (int y{0}; y < image.height(); y++)
        {
            glm::vec2 point{x, y};
            glm::vec2 center_of_rotation{image.width()/2, image.height()/2};
            glm::vec2 new_point{rotated(point, center_of_rotation ,pow((pow((x-image.width()/2),2)+pow((y-image.height()/2),2)),0.5)/10) };

            if(new_point.y<vortex.height() && new_point.x<vortex.width() && new_point.y>0 && new_point.x>0) { 
                vortex.pixel(x, y) = image.pixel(new_point.x, new_point.y);
            }
        }
    } 
    vortex.save("output/vortex.png"); 
}


 /**
 * Fait du tramage sur une image
 */
void dithering(sil::Image image) {
    for (int x{0}; x < image.width(); x++)
    {
        for (int y{0}; y < image.height(); y++)
        {   
            // On calcule la probabilité d'un pixel à être coloré en blanc en fonction de sa luminosité
            float white_proba = (image.pixel(x,y).r + image.pixel(x,y).g + image.pixel(x,y).b) / 3.f;
            if (random_float(0.f, 1.f) < white_proba) {
                image.pixel(x, y) = glm::vec3{1};
            } else {
                image.pixel(x, y) = glm::vec3{0};
            }
        }
    } 
    image.save("output/dithering.jpg"); 
}

 /**
 * Améliore le contraste d'une image
 */
void betterContrast(sil::Image image) {
    float min {1.f}; // Plus petite luminosité
    float max {0.f}; // Plus grande luminosité

    for (int x{0}; x < image.width(); x++)
    {
        for (int y{0}; y < image.height(); y++)
        {   
            // On cherche le pixel avec le moins de lumière
            if ((image.pixel(x,y).r + image.pixel(x,y).g + image.pixel(x,y).b)/3.f < min) {
                min = (image.pixel(x,y).r + image.pixel(x,y).g + image.pixel(x,y).b)/3.f;
            }
            // On cherche le pixel avec le plus de lumière
            if ((image.pixel(x,y).r + image.pixel(x,y).g + image.pixel(x,y).b)/3.f > max) {
                max = (image.pixel(x,y).r + image.pixel(x,y).g + image.pixel(x,y).b)/3.f;
            }
        }
    } 

    // Action sur les pixels
    for (int x{0}; x < image.width(); x++)
    {
        for (int y{0}; y < image.height(); y++)
        {   
            image.pixel(x,y).r -= min;
            image.pixel(x,y).g -= min;
            image.pixel(x,y).b -= min;
            
            image.pixel(x,y).r *= 1.f / max;
            image.pixel(x,y).g *= 1.f / max;
            image.pixel(x,y).b *= 1.f / max;
        }
    } 
    image.save("output/betterContrast.jpg"); 
}

 /**
 * Rend une image floue selon un niveau de flou donné
 */
sil::Image blur(sil::Image image, int level) {
    sil::Image new_image{image.width(), image.height()};
    // On parcourt tous les pixels de notre image
    for (int x{0}; x < image.width(); x++)
    {
        for (int y{0}; y < image.height(); y++)
        {
            glm::vec3 sum {0.f};
            int size {level};
            // On parcourt tous les pixels de notre matrice de flou
            for (int x_offset{-size}; x_offset < size; x_offset++)
            {
                for (int y_offset{-size}; y_offset < size; y_offset++)
                {
                    int real_x_offset{x_offset};
                    int real_y_offset{y_offset};
                    if (x+real_x_offset<0 || x+real_x_offset>=image.width())
                    {
                        real_x_offset = 0;
                    }
                    if (y+real_y_offset<0 || y+real_y_offset>=image.height())
                    {
                        real_y_offset = 0;
                    }
                    sum += image.pixel(x+real_x_offset,y+real_y_offset);
                }
            }
            // On calcule et on applique la couleur trouvée au pixel de l'image parcouru
            sum /= pow(2*size+1,2);
            new_image.pixel(x,y)=sum;
        }
    }
    new_image.save("output/blur.png"); 
    return new_image;
}

 /**
 * Permet d'appliquer un effet à une image à partir d'une matrice
 */
void applyKernel(std::vector<std::vector<float>> kernel, sil::Image & image, std::string name) {
    sil::Image new_image{image.width(), image.height()};
    // On parcourt tous les pixels de notre image
    for (int x{0}; x < image.width(); x++)
    {
        for (int y{0}; y < image.height(); y++)
        {
            glm::vec3 sum {0.f};
            int size {1};
            // On parcourt tous les pixels de notre kernel
            for (int x_offset{-size}; x_offset <= size; x_offset++)
            {
                for (int y_offset{-size}; y_offset <= size; y_offset++)
                {
                    int real_x_offset{x_offset};
                    int real_y_offset{y_offset};
                    if (x+real_x_offset<0 || x+real_x_offset>=image.width()) {
                        real_x_offset = 0;
                    }
                    if (y+real_y_offset<0 || y+real_y_offset>=image.height()) {
                        real_y_offset = 0;
                    }
                    sum += image.pixel(x+real_x_offset,y+real_y_offset) * kernel[1+real_x_offset][1+real_y_offset];
                }
            }
            // On applique la couleur trouvée au pixel de l'image parcouru
            new_image.pixel(x,y) = sum;
        }
    }
    new_image.save("output/"+name+".png"); 
}

 /**
 * Fait une différence de gaussiennes sur une image
 */
void differenceOfGaussians(sil::Image photo) {
    sil::Image image {photo};
    sil::Image big_blur {blur(photo, 10)};
    photo = image;
    sil::Image small_blur {blur(photo, 4)};
    // On soustrait une image un peu floutée à une image plus floutée
    for (int x{0}; x < image.width(); x++)
    {
        for (int y{0}; y < image.height(); y++)
        {
            image.pixel(x, y).r = big_blur.pixel(x, y).r - small_blur.pixel(x, y).r;
            image.pixel(x, y).g = big_blur.pixel(x, y).g - small_blur.pixel(x, y).g;
            image.pixel(x, y).b = big_blur.pixel(x, y).b - small_blur.pixel(x, y).b;
        }
    }
    image.save("output/differenceOfGaussians.png");
}

 /**
 * Effectue un tri des pixels selon leur luminosité
 */
void sortPixels(sil::Image image) {
    for (int x{0}; x < image.width(); x++)
    {
        // On récupère chaque ligne de pixels
        std::vector<glm::vec3> line {};
        int rand = random_int(0,image.height()-1);
        for (int y{0}; y < rand; y++)
        {
            line.push_back(image.pixel(x,y));
        }
        // On effectue le tri
        std::sort(line.begin(), line.end(), [](glm::vec3 const& color1, glm::vec3 const& color2)
        {
            return brightness(color1) < brightness(color2);
        });
        // On réafecte le tableau de pixels triés à l'image de base
        for (int i{0}; i < line.size(); i++)
        {
            image.pixel(x,i) = line[i];
        }
    }
    image.save("output/sortPixels.png");
}
