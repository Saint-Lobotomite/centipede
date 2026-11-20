#include <windows.h>
#include <esat/sprite.h>

#include "mask.hh"

void FromFile(Mask_t *mask, const char *path, 
  Vector2_t sub_position = {0,0},
  Vector2_t sub_size = {0,0}
) {
	esat::SpriteHandle sprite = esat::SpriteFromFile(path);

	if (!isZero(sub_size)) {
    printf("sub ");
    esat::SpriteHandle aux = esat::SubSprite(sprite, 
      sub_position.x, sub_position.y, 
      sub_size.x, sub_size.y
    );

    esat::SpriteRelease(sprite);

    sprite = aux;
  }

	u1 RGBA[4] = {0};

	int mx = esat::SpriteWidth(sprite);
	int my = esat::SpriteHeight(sprite);

	if (mx*my > kMask_WordCount*4) {
    printf("FromFile: %s es demasiado grande (%d x %d)", path, mx, my);
  }

	printf("%d, %d\n", mx, my);

  mask->size = {mx, my};

	for (int y = 0; y < my; y++) {
    for (int x = 0; x < mx; x++) {

      esat::SpriteGetPixel(sprite, x,y, RGBA);

      //if (RGBA[3] == 255) { // El pixel es opaco
      //  WriteBit(mask, x,y, 1);
      //}

    }
  }

	esat::SpriteRelease(sprite);
}


u1 GetIndex(Mask_t *mask, int x, int y) {
    return (y * mask->size.x + x) / 2;
}

bool IsValidPosition(Mask_t *mask, int x, int y) {
    return (
        x < mask->size.x
        && y < mask->size.y
        && GetIndex(mask, x,y) / 4 < kMask_WordCount
    );
}


u1 ReadPair(u1 word, u1 i) {
    return (word >> (i*2)) & 3;
}

void WritePair(u1 *word, u1 i, u1 v) {
	u1 selector = 3 << (i*2);

	if (v) 	*word |= selector; // bits a 1
	else 		*word &= ~selector; // bits a 0
}


u1 ReadPair(Mask_t *mask, int x, int y) {
	u1 i = GetIndex(mask, x,y);

	return ReadPair(
		mask->matrix[i / 4],
		i % 4 
	);
}

void WritePair(Mask_t, int x, int y, u1 v) {
	u1 i = GetIndex(mask, x,y);

	return WritePair(
		mask->matrix[i / 4],
		i % 4,
		v
	);
}

#endif // MASK_HH