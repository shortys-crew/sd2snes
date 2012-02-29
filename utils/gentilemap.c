#include <stdio.h>
#include <stdint.h>

int main(void) {
uint16_t tile=256;
uint16_t pad=256;
	int i,j;
	FILE *out;
	if((out=fopen("tilemap", "wb"))==NULL) {
		perror("Could not open output file 'tilemap'");
		return 1;
	}
	for(i=0; i<8; i++) {
		for(j=0; j<26; j++)	{
			fwrite(&tile, 2, 1, out);
			tile++;			
		}
		for(j=26; j<32; j++) {
			fwrite(&pad, 2, 1, out);
		}
	}
	fclose(out);
}