#include <stdio.h>
#include <stdlib.h>
#include <time.h>
struct node {
  int data;
  struct node *next;  
  struct node *prev;
  struct node *jump;
};

struct player {
  struct node *curr;
} p[4];

void display(struct node *head) {

  struct node *temp;
  temp = head;

  if (head == NULL)
    printf("There is no linked list");
  else {
    while (temp != NULL) {
      printf("%d ", temp->data);
      temp = temp->next;
    }
  }
}

struct node *createNewnode() {
  struct node *newnode;

  newnode = malloc(sizeof(struct node));
  newnode->next = NULL;
  newnode->prev = NULL;
  newnode->jump = NULL;
  return newnode;
}

struct node *createBoard() {
  struct node *newnode, *temp;
  struct node *head = NULL;

  if (head == NULL) {
    head = createNewnode();
    head->data = 1;
  }
  temp = head;
  for (int i = 1; i < 100; i++) {
    newnode = createNewnode();
    newnode->data = i + 1;
    temp->next = newnode;
    newnode->prev = temp;
    temp = temp->next;
  }

  return head;
}


void ladder(struct node *head) {
  struct node *l1s, *l1e, *l2s, *l2e, *l3s, *l3e, *l4s, *l4e, *temp;
  temp = head;
  if (head == NULL)
    printf("No board is created.....");
  else {
    while (temp->next != NULL) {
      switch (temp->data) {
      case 3:
        l1s = temp;
        break;
      case 25:
        l1e = temp;
        break;
      case 80:
        l2s = temp;
        break;
      case 95:
        l2e = temp;
        break;
      case 42:
        l3s = temp;
        break;
      case 65:
        l3e = temp;
        break;
      case 24:
        l4s = temp;
        break;
      case 93:
        l4e = temp;
        break;
      }
      temp = temp->next;
    }
    l1s->jump = l1e;
    l2s->jump = l2e;
    l3s->jump = l3e;
    l4s->jump = l4e;
  }
}

void snake(struct node *head) {
  struct node *l1s, *l1e, *l2s, *l2e, *l3s, *l3e, *l4s, *l4e, *temp;
  temp = head;
  if (head == NULL)
    printf("No board is created.....");
  else {
    while (temp->next != NULL) {
      switch (temp->data) {
      case 94:
        l1s = temp;
        break;
      case 26:
        l1e = temp;
        break;
      case 95:
        l2s = temp;
        break;
      case 38:
        l2e = temp;
        break;
      case 99:
        l3s = temp;
        break;
      case 2:
        l3e = temp;
        break;
      case 66:
        l4s = temp;
        break;
      case 40:
        l4e = temp;
        break;
      }
      temp = temp->next;
    }
    l1s->jump = l1e;
    l2s->jump = l2e;
    l3s->jump = l3e;
    l4s->jump = l4e;
  }
}

int rollDice(int player_no) {
  int high = 10, low = 1;

  
  int p;
  printf("\nPlayer[%d] press Enter to roll the dice", player_no);
  
  //while (getchar() != '\n'); //Waiting for the user to press enter.
  
  p = (rand() % high) + low;
  printf("Player[%d] got:%d\n", player_no,p);
                           
  return p;
}

struct node* move(int count,struct node * curr,int i){
  if(count>6){
    int backward = 0;
    switch(count){
      case 7: 
        backward++;
        break;
      case 8:
        backward+=2;
        break;
      case 9:
        backward+=3;
        break;
      case 10:
        backward+=4;
        break;    
    }

    while(backward!=0 && (curr->data)-backward>=0) {
      curr = curr->prev;
      backward--;
    }
    if(curr->jump!=NULL) curr = curr->jump;
  }
  else{
    while(count!=0 && (curr->data)+count<=100){
      curr = curr->next;
      count--;
    }
    if(curr->jump!=NULL){
      curr = curr->jump;
      printf("\n\nPlayer %d got jumped from his position... to:%d\n\n",i,curr->data);
    }
    }    
  return curr;  
}


int checkForWinner(struct node* curr){
  if(curr->data == 100)return 1;
  else return 0;
  
}
void gameplay(struct node *head) {
  int currPlayerCount = 4;
  
  for(int i=0; i<4; i++) {
      p[i].curr = head;
  }
  
  int cc1=0, cc2=0, cc3=0, cc4=0;
  int gameOver = 0;   // Flag to indicate game status
  
  while (!gameOver) {
    for (int i = 0; i < 4; i++) {
        int diceRoll = rollDice(i + 1);
        if(!checkForWinner(p[i].curr)) {
            p[i].curr = move(diceRoll, p[i].curr, i+1);
        }
        else {
            if (i == 0 && cc1 == 0) { 
                printf("player1 won the game.\n");
                cc1++;
            } else if (i == 1 && cc2 == 0) {
                printf("player2 won the game.\n");
                cc2++;
            } else if (i == 2 && cc3 == 0) {
                printf("player3 won the game.\n");
                cc3++;
            } else if (i == 3 && cc4 == 0) {
                printf("player4 won the game.\n");
                cc4++;
            }
            gameOver = 1;
            break;  // Exit the loop when a player wins
        }
    }

    printf("\nplayer 1 at the position:%d\n", p[0].curr->data);
    printf("player 2 at the position:%d\n", p[1].curr->data);
    printf("player 3 at the position:%d\n", p[2].curr->data);
    printf("player 4 at the position:%d\n", p[3].curr->data);
  }

  printf("Game over!!!!\n");
}

int main() {
  struct node *head;
  srand(time(NULL));
  head = createBoard();
  ladder(head);
  snake(head);  
  display(head);
  gameplay(head);
  
  return 0;
}