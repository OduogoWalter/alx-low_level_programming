#include <stdio.h>
#include <string.h>

/*Define the struct dog*/

struct dog
{
	char name[100];
	float age;
	char owner[100];
};

/*Function to initialize a struct dog*/

void init_dog(struct dog *d, char *name, float age, char *owner)

{
    /* Use strncpy to safely copy the strings into the struct field*/

	strncpy(d->name, name, sizeof(d->name));
	d->name[sizeof(d->name) - 1] = '\0'; /*Ensure null-terminated string*/

	d->age = age;

	strncpy(d->owner, owner, sizeof(d->owner));
	d->owner[sizeof(d->owner) - 1] = '\0'; /*Ensure null-terminated string*/
}

int main(void)
{
	struct dog myDog; /*Declare a struct dog variable*/

	/*Initialize the struct dog using the init_dog function*/
	init_dog(&myDog, "Buddy", 2.5, "John");

	/*Print the initialized dog's information*/

	printf("Dog's Name: %s\n", myDog.name);
	printf("Dog's Age: %.2f\n", myDog.age);
	printf("Owner: %s\n", myDog.owner);

	return (0);
}
