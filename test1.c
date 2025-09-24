#include <stdio.h>
#include <string.h>

int main() 
{
	char i[100];
	while (1)
	{
		printf("请输入: ");
		scanf("%s", &i);
	if (strcmp(i, "Dian") == 0)
		{
			printf("2022\n");
		}
		
	else if (strcmp(i, "Quit") == 0)
		{
			break;
		}
		
	else
		{
			printf("Error\n");
		}
		
		
	}
	
	return 0;
}