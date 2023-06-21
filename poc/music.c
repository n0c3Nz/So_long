#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#pragma pack(push, 1) // Asegura que no haya relleno en la estructura
typedef struct
{
    char chunkID[4];
    uint32_t chunkSize;
    char format[4];
    char subchunk1ID[4];
    uint32_t subchunk1Size;
    uint16_t audioFormat;
    uint16_t numChannels;
    uint32_t sampleRate;
    uint32_t byteRate;
    uint16_t blockAlign;
    uint16_t bitsPerSample;
} WAVHeader;
#pragma pack(pop)

int main()
{
    const char* filePath = "/home/odin/Documents/42/so_long/audio/Route.wav"; // Ruta al archivo de audio

    // Abrir el archivo de audio en modo de lectura binaria
    FILE* file = fopen(filePath, "rb");
    if (file == NULL)
    {
        printf("No se pudo abrir el archivo de audio\n");
        return 1;
    }

    // Leer el encabezado del archivo WAV
    WAVHeader header;
    fread(&header, sizeof(WAVHeader), 1, file);

    // Verificar que el archivo WAV tenga el formato adecuado
    if (strncmp(header.chunkID, "RIFF", 4) != 0 ||
        strncmp(header.format, "WAVE", 4) != 0 ||
        strncmp(header.subchunk1ID, "fmt ", 4) != 0)
    {
        printf("El archivo de audio no tiene el formato WAV esperado\n");
        fclose(file);
        return 1;
    }

    // Saltar los bytes adicionales del bloque fmt
    fseek(file, header.subchunk1Size - sizeof(WAVHeader) + 8, SEEK_CUR);

    // Leer el bloque de datos de audio
    char dataChunkID[4];
    uint32_t dataChunkSize;
    fread(&dataChunkID, sizeof(dataChunkID), 1, file);
    fread(&dataChunkSize, sizeof(dataChunkSize), 1, file);

    // Verificar que el bloque de datos tenga el formato adecuado
    if (strncmp(dataChunkID, "data", 4) != 0)
    {
        printf("El archivo de audio no tiene el formato WAV esperado\n");
        fclose(file);
        return 1;
    }

    // Calcular el tamaño total de los datos de audio
    uint32_t dataSize = dataChunkSize;

    // Leer y reproducir los datos de audio
    uint8_t* audioData = (uint8_t*)malloc(dataSize);
    fread(audioData, 1, dataSize, file);

    // Reproducir el audio (aquí puedes implementar tu lógica de reproducción)

    // ...

    // Liberar la memoria y cerrar el archivo
    free(audioData);
    fclose(file);

    return 0;
}
