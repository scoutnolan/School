#define key ((key_t)(1234))
#define MAX 100

struct msgstruct { 
	long msg_type;
	char msg_text[MAX];
};
