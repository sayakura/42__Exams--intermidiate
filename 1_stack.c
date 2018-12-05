#include <stdlib.h>

typedef struct s_node {
	void          *content;
	struct s_node *next;
} Node;

typedef struct s_stack {
	struct s_node *top;
} Stack;

struct s_stack *init(void)
{
	Stack *s = malloc(sizeof(Stack));
	s->top = NULL;
	return (s);
}

void *pop(struct s_stack *stack)
{
	void *data;
	Node *temp;
	if (stack && stack->top)
	{
		temp = stack->top;
		stack->top = stack->top->next;
		data = temp->content;
		free(temp);
		return (data);
	} else {
		return (NULL);
	}
}

void push(struct s_stack *stack, void *content)
{
	Node *temp = malloc(sizeof(Node));
	temp->content = content;
	temp->next = NULL;
	if (stack && !stack->top){
		stack->top = temp;
	} else if (stack->top) {
		temp->next = stack->top;
		stack->top = temp;
	} 
}

void *peek(struct s_stack *stack)
{
	if (stack && stack->top)
		return stack->top->content;
	return (NULL);
}

int isEmpty(struct s_stack *stack)
{
	if (stack && !stack->top)
		return (1);
	return (0);
}
/*
#include <stdio.h>
int		main(void)
{
	Stack *s = init();
	printf("I, P;%d\n", (int)pop(s));
	push(s, (void *)10);	
	printf("P 10, P:%d\n", (int)pop(s));
	push(s, (void *)100);
	printf("P 100, P:%d\n", (int)peek(s));
	printf("E:%d\n", isEmpty(s));
	push(s, (void *)3);	
	printf("P 3, P:%d\n", (int)peek(s));
	pop(s);
	printf("pop, Peek:%d\n", (int)peek(s));
	pop(s);
	printf("pop, Peek:%d\n", (int)peek(s));
}*/
