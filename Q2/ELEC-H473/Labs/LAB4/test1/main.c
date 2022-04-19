#include <stdio.h>
#include <stdlib.h>
int main()
{

//read_image_from_file
    int start_time;
    int end_time;
    int computetime;
    int W=1024, H=1024;
    int i;
    int treshold=125;
    unsigned char*src;
    unsigned char*dst;
    src = (unsigned char*) malloc (W*H*sizeof(unsigned char));
    dst = (unsigned char*) malloc (W*H*sizeof(unsigned char));
    if (src == NULL || dst == NULL)
    {
        printf ("Out of memory!");
        exit (1);

    }
    FILE*fp1 = fopen("Escher.raw","r");

    if (fp1 != NULL)
    {
// we read data if file opened
        fread(src, sizeof(unsigned char), W*H, fp1);
        fclose(fp1);
    } // and we close the pointer
    else
    {
        printf("Can¡¯t open specified file!");
        exit(1);
    }


    start_time = clock();

    for (i=0; i<W*H; i++)
    {
        if (src[i] < treshold)
        {
            dst[i] = 0;
        }
        else
        {
            dst[i] = 255;
        }
    }

    end_time = clock();

    computetime = end_time - start_time ;
    printf("%d\n",computetime);

//write_image_result


    FILE*fp2 = fopen("Eschernez.raw","w");

    if (fp2 != NULL)
    {
// we read data if file opened

        fwrite(dst, sizeof(unsigned char), W*H, fp2);

        fclose(fp2);
    } // and we close the pointer
    else
    {
        printf("Can¡¯t open specified file!");
        exit(1);
    }


    free(src);// we do this to avoid memory leaks
    free(dst);
    return 0;

}
