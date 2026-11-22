#include <stdio.h>

#include "draw.hh"

#include "game.hh"
#include "structs/mask.hh"
#include "loader.hh"


static bool ShouldPaint(Mask_t *mask,
  unsigned int x, unsigned y,
  unsigned char RGBA[4], bool ex_nihilo
) {
    u1 i = ReadPair(mask, x,y);
    if (!i) return false; // No hay pixel

    unsigned char new_RGBA[4];
    ReadPalette(i-1, new_RGBA);

    bool ret = ex_nihilo || (
      new_RGBA[0] == RGBA[0]
      && new_RGBA[1] == RGBA[1]
      && new_RGBA[2] == RGBA[2]
      && new_RGBA[3] == RGBA[3]
    );

    RGBA[0] = new_RGBA[0];
    RGBA[1] = new_RGBA[1];
    RGBA[2] = new_RGBA[2];
    RGBA[3] = new_RGBA[3];

    return ret;
}



void Draw(Body_t *self) {
	Mask_t *mask = GetMask(&self->track);

	u1 RGBA[4] = {0};
	int ox = 0; // Origin x
	int length = 0;
  u1 color = 0; // Index en la paleta
  u1 new_color = 0;

	for (int y = 0; y < mask->size.y; y++) {
    ox = 0;
    length = 0;
    color = 0;

		// x == size.x es lo que cierra
		for (int x = 0; x <= mask->size.x; x++) {

      new_color = (x < mask->size.x) ? ReadPair(mask, x,y) : 0; // Evitamos leer un pixel que no existe
      
      if (length > 0 && new_color != color) { // Si llevamos camino y acabamos de cambiar de color, dibujamos
        ReadPalette(color -1, RGBA);

        DrawRectangle(
          { self->position.x + ox, self->position.y + y },
          { length, 1 },
          RGBA
        );

        length = 0;
      }

      if (new_color) { // El pixel que acabamos de leer no esta vacio
        if (length == 0) { // Acabamos de dibujar lo anterior o venimos de la nada
          color = new_color; 
          ox = x;
        }
        
        length++;
      }

		}

	}

}







void DrawRectangle(Vector2_t position, Vector2_t size, unsigned char RGBA[4]){
    esat::DrawSetFillColor(RGBA[0], RGBA[1], RGBA[2]);

    float points[10] = {

        float(position.x) * kPixelScale,
        float(position.y) * kPixelScale,

        float(position.x + size.x) * kPixelScale,
        float(position.y) * kPixelScale,

        float(position.x + size.x) * kPixelScale,
        float(position.y + size.y) * kPixelScale,

        float(position.x) * kPixelScale,
        float(position.y + size.y) * kPixelScale,

        float(position.x) * kPixelScale,
        float(position.y) * kPixelScale,
    };

    esat::DrawSolidPath(points, 5);
}


