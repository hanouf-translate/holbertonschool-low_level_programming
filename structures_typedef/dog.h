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

#endif /* DOG_H */
