#include <stdio.h>
#include <string.h>

struct dog

{
	/*initialize variable*/

	char name[100];
	float age;
	char owner[100];
};

void init_dog(struct dog *d, char *name, float age, char *owner)

{
	/*Check for NULL pointers to avoid potential crashes*/

	strncpy(d->name, name, sizeof(d->name));
	d->name[sizeof(d->name) - 1] = '\0';

	d->age = age;

	strncpy(d->owner, owner, sizeof(d->owner));
	d->owner[sizeof(d->owner) - 1] = '\0';
}

int main(void)

{
	/*Print the initialized dog's information*/

	struct dog myDog;

	init_dog(&myDog, "Buddy", 2.5, "John");

	printf("Dog's Name: %s\n", myDog.name);
	printf("Dog's Age: %.2f\n", myDog.age);
	printf("Owner: %s\n", myDog.owner);

	return (0);
}
