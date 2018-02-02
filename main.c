#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define DATE_LEN 25
#define CITY_COUNTRY_LEN 30


typedef struct scrapedata
{
	char date[DATE_LEN];
	char country[CITY_COUNTRY_LEN];
        char rest[1000];
        char justCountry[20];
} scrapedata;

int main()
{
	int lines = 0;
	int i;
        scanf("%d", &lines);
	printf("number = %d\n", lines);
	
	scrapedata *m = (scrapedata *) malloc(lines * sizeof(scrapedata));
	for (i = 0; i < lines; i++)
	{
            scanf("%[^,],", m[i].date);
            scanf("%[^,]", m[i].country);
            scanf("%[^\r]\r", m[i].rest);
	}
	
        for(i = 0; i < lines; i++)
        {
            if(strchr(m[i].country, '('))
            {
                const char *result = strchr(m[i].country, '(');
                int lenC = strlen(result) - 1;
                strncpy(m[i].justCountry, (strchr(m[i].country, '(')) + 1, lenC - 1);
                m[i].country[strlen(m[i].country) - lenC - 2] = '\0';
                printf("%s,%s,%s%s\n", m[i].date, m[i].country, m[i].justCountry, m[i].rest);
            }
            else
            {
                printf("%s,%s,%s\n", m[i].date, m[i].country, m[i].rest);
            }
        }

        free(m);
	return 0;
}
