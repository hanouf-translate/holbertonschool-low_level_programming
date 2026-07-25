#ifndef DOG_H
#define DOG_H

/**
 * struct dog - Structure representing a dog's basic info
 * @name: Pointer to char (string) for the dog's name
 * @age: Float for the dog's age
 * @owner: Pointer to char (string) for the owner's name
 *
 * Description: Header file defining a new data structure for a dog.
 */
struct dog
{
	char *name;
	float age;
	char *owner;
};

/**
 * dog_t - Typedef for struct dog
 */
typedef struct dog dog_t;

void init_dog(struct dog *d, char *name, float age, char *owner);
void print_dog(struct dog *d);
dog_t *new_dog(char *name, float age, char *owner);
void free_dog(dog_t *d);

#endif /* DOG_H */
