#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{

	int i;
	char* arg;


	printf("\n#################  loading...  ###################\n");


	if(argc < 2)
	{
		printf("usage : ./docker-node [node|npm] [ARGS]...\n\n");
		exit(0);

	}else if(strcmp(argv[1], "node") == 0 || strcmp(argv[1], "npm") == 0){

		arg = (char*) malloc(100000 * sizeof(char));
		strcat(arg, "docker run -it --rm --name nodejs -v $PWD:/usr/src/app -w /usr/src/app node ");
		
		for(i = 0; i < argc - 1 ; i++)
		{
			strcat(arg, argv[i + 1]);
			strcat(arg, " ");
		}

		system(arg);
		exit(0);
	}

	printf("usage : ./docker-node [node|npm] [ARGS]...\n\n");
	
	free(arg);
	
	return 0;
}
