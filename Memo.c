/*
 *	A program that uses linked list to leave a memo
 */

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

typedef struct stringList{
	char charArray[50];
	struct stringList* next;
	struct stringList* previous;
} stringList;

void addString(stringList*);
void printString(stringList*);
void deleteList(stringList*);
void setPrevious(stringList*);
void removeString(stringList*, char*);
void setUnion(stringList*, stringList*, stringList*);
void sortString(stringList*, stringList*);
int strcmpa(char*, char*);
void stringIntersection(stringList*, stringList*, stringList*);
void symmetricDifference(stringList*, stringList*, stringList*);
void copyString(stringList*, stringList*);
int checkDuplicate(stringList*, char*);

int main() {
	printf("Welcome!\n");
	int loop = 1;
	//Create arrays of pointer
	stringList **pointerArray;
	pointerArray = malloc(10 * sizeof(stringList*));
	//Check if pointerArray has been created
	if (pointerArray == NULL) {
		printf("pointerArray is NULL\n");
		return 0;
	}
	int i;
	//Set next and previous value of every element in pointerArray
	//to NULL
	for (i = 0; i < 10; i++) {
		pointerArray[i] = malloc(sizeof(stringList));
		if (pointerArray[i] == NULL) {
			printf("pointerArray[i] is NULL\n");
			return 0;
		}
		pointerArray[i]->next = NULL;
		pointerArray[i]->previous = NULL;
	}
	char answer;
	char answer2;
	char answer3;
	char answer4;
	int number2;
	int number3;
	int number4;
	while(loop){
		printf("Enter 'a' to add string\n");
		printf("Enter 'r' to remove string\n");
		printf("Enter 'u' to show union\n");
		printf("Enter 'i' to show intersection\n");
		printf("Enter 's' to show symmetric difference\n");
		printf("Enter 'c' to copy\n");
		printf("Enter 'z' to clear\n");
		printf("Enter 'p' to print\n");
		printf("Enter 'q' to quit\n");
		scanf(" %c", &answer);
		switch (answer) {
			case 'A':
			case 'a':
				printf("set: ");
				scanf(" %c", &answer2);
				//If answer2 is not a single character and not 0~9, display message
				if (getchar() != '\n' && answer2 >= 48 && answer2 <= 57) {
					printf("Please use set number 0~9\n");
					break;
				}
				number2 = answer2 - '0';
				addString(*(pointerArray + number2));
				setPrevious(*(pointerArray + number2));
				break;
			case 'P':
			case 'p':
				printf("set: ");
				scanf(" %c", &answer2);
				if (getchar() != '\n' && answer2 >= 48 && answer2 <= 57) {
					printf("Please use set number 0~9\n");
					break;
				}
				number2 = answer2 - '0';
				printString(*(pointerArray + number2));
				setPrevious(*(pointerArray + number2));
				break;
			case 'Z':
			case 'z':
				printf("set: ");
				scanf(" %c", &answer2);
				if (getchar() != '\n' && answer2 >= 48 && answer2 <= 57) {
					printf("Please use set number 0~9\n");
					break;
				}
				number2 = answer2 - '0';
				deleteList(*(pointerArray + number2));
				break;
			case 'U':
			case 'u':
				printf("destination set: ");
				scanf(" %c", &answer2);
				printf("first operand: ");
				scanf(" %c", &answer3);
				printf("second operand: ");
				scanf(" %c", &answer4);
				if (getchar() != '\n' && answer2 >= 48 && answer2 <= 57 && answer3 >= 48\
				    && answer3 <= 57 && answer4 >= 48 && answer4 <= 57) {
					printf("Please use set number 0~9\n");
					break;
				}
				number2 = answer2 - '0';
				number3 = answer3 - '0';
				number4 = answer4 - '0';
				setUnion(*(pointerArray + number2), *(pointerArray + number3), *(pointerArray + number4));
				setPrevious(*(pointerArray + number2));
				break;
			case 'I':
			case 'i':
				printf("destination set: ");
				scanf(" %c", &answer2);
				printf("first operand: ");
				scanf(" %c", &answer3);
				printf("second operand: ");
				scanf(" %c", &answer4);
				if (getchar() != '\n' && answer2 >= 48 && answer2 <= 57 && answer3 >= 48\
				    && answer3 <= 57 && answer4 >= 48 && answer4 <= 57) {
					printf("Please use set number 0~9\n");
					break;
				}
				number2 = answer2 - '0';
				number3 = answer3 - '0';
				number4 = answer4 - '0';
				deleteList(*(pointerArray+number2));
				stringIntersection(*(pointerArray + number2), *(pointerArray + number3), *(pointerArray + number4));
				stringIntersection(*(pointerArray + number2), *(pointerArray + number4), *(pointerArray + number3));
				setPrevious(*(pointerArray + number2));
				break;
			case 'S':
			case 's':
				printf("destination set: ");
				scanf(" %c", &answer2);
				printf("first operand: ");
				scanf(" %c", &answer3);
				printf("second operand: ");
				scanf(" %c", &answer4);
				if (getchar() != '\n' && answer2 >= 48 && answer2 <= 57 && answer3 >= 48\
				    && answer3 <= 57 && answer4 >= 48 && answer4 <= 57) {
					printf("Please use set number 0~9\n");
					break;
				}
				number2 = answer2 - '0';
				number3 = answer3 - '0';
				number4 = answer4 - '0';
				deleteList(*(pointerArray + number2));
				symmetricDifference(*(pointerArray + number2), *(pointerArray + number3), *(pointerArray + number4));
				symmetricDifference(*(pointerArray + number2), *(pointerArray + number4), *(pointerArray + number3));
				setPrevious(*(pointerArray + number2));
				break;
			case 'C':
			case 'c':
				printf("destination set: ");
				scanf(" %c", &answer2);
				printf("first operand: ");
				scanf(" %c", &answer3);
				if (getchar() != '\n' && answer2 >= 48 && answer2 <= 57 && answer3 >= 48\
				    && answer3 <= 57 && answer4 >= 48 && answer4 <= 57) {
					printf("Please use set number 0~9\n");
					break;
				}
				number2 = answer2 - '0';
				number3 = answer3 - '0';
				deleteList(*(pointerArray + number2));
				copyString(*(pointerArray + number2), *(pointerArray + number3));
				setPrevious(*(pointerArray + number2));
				break;
			case 'R':
			case 'r':
				printf("set: ");
				scanf(" %c", &answer2);
				if (getchar() != '\n' && answer2 >= 48 && answer2 <= 57 && answer3 >= 48\
				    && answer3 <= 57 && answer4 >= 48 && answer4 <= 57) {
					printf("Please use set number 0~9\n");
					break;
				}
				number2 = answer2 - '0';
				char stringRemove[50];
				fgets(stringRemove, 50, stdin);
				stringRemove[strlen(stringRemove)-1] = '\0';
				removeString(*(pointerArray + number2), stringRemove);
				break;
			case 'Q':
			case 'q':
				loop = 0;
				break;
			default:
				printf("Please choose again\n");
		}
	}
	//Free every elemt in every linked list
	for (i = 0; i < 10; i++) {
		deleteList(*(pointerArray+i));
		free(pointerArray[i]);
	}
	//Free array of pointers
	free(pointerArray);
	return 0;
}

//This function is used to add string to linked list
void addString(stringList *head) {
	stringList *newList;
	newList = malloc(sizeof(stringList));
	//Check if newList has been created
	if (newList == NULL) {
		printf("newList is NULL\n");
		exit(0);
	}
	printf("string: ");
	fgets(newList -> charArray, 50, stdin);
	//Remove \n from newList -> charArray
	newList -> charArray[strlen(newList -> charArray)-1] = '\0';
	newList -> next = NULL;
	//Call sortString
	sortString(head, newList);
}

//This function is used to add and sort strings in linked list
void sortString(stringList *node, stringList *newList){
	int headCheck = 0;
	char array[50];
	int i = 1;
	strcpy(array, newList -> charArray);
	//If node does not have anything in node -> next
	//Simply assign newList as node -> next
	if (node -> next == NULL) {
		node -> next = newList;
	}
	else {
		while(1) {
			//Check if there is duplicate in node using checkDuplicate
			//If there is, do not add and sort newList in node
			if (checkDuplicate(node, array) == 1) {
				free(newList);
				i = 0;
				break;
			} else {
				break;
			}
		}
		while(i) {
			//If next charArray is greater than newList -> charArray,
			//assign it here 
			if (headCheck == 0 && strcmpa(node -> next -> charArray, newList -> charArray) > 0) {
				stringList *newList2;
				newList2 = malloc(sizeof(stringList));
				if (newList2 == NULL) {
					printf("newList2 is NULL\n");
					exit(0);
				}
				newList2 -> next = node -> next;
				newList -> next = newList2 -> next;
				node -> next = newList;
				free(newList2);
				break;
			}
			if (headCheck == 0) {
				node = node -> next;
				headCheck = 1;
			}
			//If there is something after node and next charArray is greater than newList -> charArray,
			//assign it here
			else if (node -> next != NULL && strcmpa(node -> next -> charArray, newList -> charArray) > 0) {
				stringList *newList2;
				newList2 = malloc(sizeof(stringList));
				if (newList2 == NULL) {
					printf("newList2 is NULL\n");
					exit(0);
				}
				newList2 -> next = node -> next;
				node -> next = newList;
				node -> next -> next = newList2 -> next;
				free(newList2);
				break;
			}
			//If newList -> charArray is greater than any of node -> charArray,
			//assign it at the end
			else if (node -> next == NULL) {
				node -> next = newList;
				break;
			}
			//Else simply go to next node
			else {
				node = node -> next;
			}
		}
	}
}

//This function is used to print string
void printString(stringList* node) {
	int j = 0;
	printf("{");
	if (node -> next == NULL) {
		printf("}\n");
	}
	else {
		node = node -> next;
		while(1) {
			if (node -> next != NULL) {
				printf("%s, ", node->charArray);
				node = node -> next;
				j += 1;
			} else {
				printf("%s}\n", node->charArray);
				break;
			}
		}
	}
}

//This function is used to delete list
void deleteList(stringList* node) {
	if (node -> next != NULL) {
		node = node -> next;
	}
	int i = 1;
	while (i) {
		if (node -> next != NULL) {
			node = node -> next;
		} else {
			if (node -> previous != NULL) {
				node = node -> previous;
				free(node -> next);
				node -> next = NULL;
			}
			else {
				i = 0;
			}
		}
	}
}

//This function is used to set union
void setUnion(stringList* node, stringList* set1, stringList* set2) {
	//Delete list before assigning union
	deleteList(node);
	//If there is set1 -> next, assign set1 to node
	while(set1 -> next != NULL) {
		set1 = set1 -> next;
		stringList *newList;
		newList = malloc(sizeof(stringList));
		//Check if newList has been created
		if (newList == NULL) {
			printf("newList is NULL\n");
			exit(0);
		}
		newList -> next = NULL;
		strcpy(newList -> charArray, set1 -> charArray);
		//Will add, sort, and check duplicate
		sortString(node, newList);
	}
	//If there is set2 -> next, assign set2 to node
	while(set2 -> next != NULL) {
		set2 = set2 -> next;
		stringList *newList2;
		newList2 = malloc(sizeof(stringList));
		//Check if newList has been created
		if (newList2 == NULL) {
			printf("newList2 is NULL\n");
			exit(0);
		}
		newList2 -> next = NULL;
		strcpy(newList2 -> charArray, set2 -> charArray);
		//Will add, sort, and check duplicate
		sortString(node, newList2);
	}

}

//This function is used to set previous elemnt in stringList
//Previous is used in deleteList
void setPrevious(stringList *node) {
	while(1) {
		if (node -> next != NULL) {
			node -> next -> previous = node;
			node = node -> next;
		} else {
			break;
		}
	}
}

//Provided strcmpa function
int strcmpa(char *s1, char *s2) {
	while (*s1 && tolower(*s1) == tolower(*s2)) {
		s1++;
		s2++;
	}
	return tolower(*s1) - tolower(*s2);
}

//This function is used to remove specific string from list
void removeString(stringList* node, char* s) {
	node = node -> next;
	//Loop until node -> next is NULL
	while(1) {
		if (node -> next != NULL) {
			//Use strcmpa to check current node -> charArray and s is same
			//If it is, remove current node
			if (node -> charArray != NULL && strcmpa(node -> charArray, s) == 0) {
				node = node -> previous;
				node -> next = node -> next -> next;
				free(node -> next -> previous);
				node -> next -> previous = node;
				break;
			}
		//Use strcmpa to check current node -> charArray and s is same when node -> next is NULL
		//If it is, remove current node
		} else if (node -> charArray != NULL && strcmpa(node -> charArray, s) == 0) {
			node = node -> previous;
			free(node -> next);
			node -> next = NULL;
			break;
		}
		if (node -> next != NULL) {
			node = node -> next;
		} else {
			break;
		}
	}
}

//This function is used to copy list
void copyString(stringList* node, stringList* set1) {
	set1 = set1 -> next;
	while(1) {
		//If set1 -> next is not NULL
		//Copy charArray from set1 and assign it to
		//charArryay of node
		if (set1 -> next != NULL) {
			stringList* newList;
			newList = malloc(sizeof(stringList));
			if (newList == NULL) {
				printf("newList is NULL\n");
				exit(0);
			}
			strcpy(newList->charArray, set1->charArray);
			newList -> next = NULL;
			sortString(node, newList);
			//Move to next node and set1
			node = node -> next;
			set1 = set1 -> next;
		//If set1 -> next is NULL
		//Copy charArray from set1 and assign it to
		//charArray of node then break
		} else {
			stringList* newList2;
			newList2 = malloc(sizeof(stringList));
			if (newList2 == NULL) {
				printf("newList2 is NULL\n");
				exit(0);
			}
			strcpy(newList2 -> charArray, set1 -> charArray);
			newList2 -> next = NULL;
			sortString(node, newList2);
			node = node -> next;
			set1 = set1 -> next;
			break;
		}
	}
}


//This function is used to show symmetric difference
void symmetricDifference(stringList* node, stringList* set1, stringList* set2) {
	int check = 0;
	while(1) {
		char array[50];
		if (check == 0) {
			check = 1;
			set1 = set1 -> next;
		}
		if (check == 1) {
			strcpy(array, set1 -> charArray);
		}
		//If checkDuplicate(set2, array) is not 0, there is symmetric difference
		//Move to next set1
		if (set1 -> next != NULL && check == 1 && checkDuplicate(set2, array) != 0) {
			set1 = set1 -> next;
		//If checkDuplicate(set2, array) is 0, there is no symmetric difference
		//Copy current set1 to node
		} else if (set1 -> next != NULL && check == 1 && checkDuplicate(set2, array) == 0) {
			stringList* newList;
			newList = malloc(sizeof(stringList));
			if (newList == NULL) {
				printf("newList not created\n");
				exit(0);
			}
			strcpy(newList -> charArray, set1 -> charArray);
			newList -> next = NULL;
			sortString(node, newList);
			set1 = set1 -> next;
		//If set1 -> next is NULL and there is symmetric difference
		//break
		} else if (set1 -> next == NULL && check == 1 && checkDuplicate(set2, array) != 0) {
			break;
		//If set1 -> next is NULL and there is no symmetric difference
		//Copy current set1 to node and break
		} else if (set1 -> next == NULL && check == 1 && checkDuplicate(set2, array) == 0) {
			stringList* newList;
			newList = malloc(sizeof(stringList));
			if (newList == NULL) {
				printf("newList not created\n");
				exit(0);
			}
			strcpy(newList -> charArray, set1 -> charArray);
			newList -> next = NULL;
			sortString(node, newList);
			break;
		}
	}
}

//This function is used to show intersection
void stringIntersection(stringList* node, stringList* set1, stringList* set2) {
	int check = 0;
	while(1) {
		char array[50];
		if (check == 0) {
			check = 1;
			set1 = set1 -> next;
		}
		if (check == 1) {
			strcpy(array, set1 -> charArray);
		}
		//If checkDuplicate(set2, array) is 0, there is no duplicate
		//Move to next set1
		if (set1 -> next != NULL && check == 1 && checkDuplicate(set2, array) == 0) {
			set1 = set1 -> next;
		//If checkDuplicate(set2, array) is not 0, there is duplicate
		//Copy current set1 to node and move to next set1
		} else if (set1 -> next != NULL && check == 1 && checkDuplicate(set2, array) != 0) {
			stringList* newList;
			newList = malloc(sizeof(stringList));
			if (newList == NULL) {
				printf("newList not created\n");
				exit(0);
			}
			strcpy(newList -> charArray, set1 -> charArray);
			newList -> next = NULL;
			sortString(node, newList);
			set1 = set1 -> next;
		//If set1 -> next is NULL and checkDuplicate(set2, array) is 0, there is no duplicate
		//Break
		} else if (set1 -> next == NULL && check == 1 && checkDuplicate(set2, array) == 0) {
				break;
		//If set1 -> next is NULL and checkDuplicate(set2, array) is 0, there is duplicate
		//Copy current set1 to node and break
		} else if (set1 -> next == NULL && check == 1 && checkDuplicate(set2, array) != 0) {
			stringList* newList;
			newList = malloc(sizeof(stringList));
			if (newList == NULL) {
				printf("newList not created\n");
				exit(0);
			}
			strcpy(newList -> charArray, set1 -> charArray);
			newList -> next = NULL;
			sortString(node, newList);
			break;
		}
	}
}

//This function is used to check duplicate
int checkDuplicate(stringList* node, char* s) {
	node = node -> next;
	while(1) {
		//If strcmpa(node -> charArray, s) is 0, there is duplicate
		//Return 1
		if (node -> charArray != NULL && strcmpa(node -> charArray, s) == 0){
			return 1;
		//Else, if node -> next is not NULL move to next node
		//Otherwise, return 0 since there is no duplicate
		} else {
			if (node -> next != NULL) {
				node = node -> next;
			}
			else {
				return 0;
			}
		}
	}
}
