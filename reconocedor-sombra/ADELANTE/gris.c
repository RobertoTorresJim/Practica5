
#include <stdio.h>
#include "ppm.h"


main ()
{
   PPM pic, gris;
   PIXEL p;
   unsigned char y;
  
   pic.filename = "budapest.ppm";
   load_picture (&pic);

   gris.horizontal = pic.horizontal;
   gris.vertical = pic.vertical;
   gris.key = BYN;
   gris.filename = "gris.ppm";
   create_picture (&gris);


   for (p.y = 0 ; p.y < pic.vertical;p.y++)
     for (p.x = 0 ; p.x < pic.horizontal;p.x++) {
       get_pixel (pic, &p);

       y = p.rojo*0.299 + p.verde*0.587 + p.azul*0.114;

       p.gris = y;

       put_pixel (gris, p);
       
     }
   
   save_picture (gris);

}


