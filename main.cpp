/* 
 * 
 * 
 */
#include <iostream>
#include <ctime>
#include <cmath>
#include <cstdlib>
#include <string>

using namespace std;


int rand_0toN1(int n);
int draw_a_card();
int select_next_available(int n);

bool card_drawn[52];
int cards_remaining = 52;

string suits[4] = {"hearts", "diamonds", "spades", "clubs"};
string ranks[13] = {"ace", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "jack", "queen", "king"};


int main() {

    srand(time(NULL));

    int rounds, i, rank, previousRank, userGuess;
    

    int score;
    
    while (true ) {
        cout << "Welcome to High low" << endl << endl;  
        cout << "How many rounds do you want to play? (0 to exit): ";

        cin >> rounds;
        
        score = 0;
        
        if (rounds == 0) {
            break;
        }

        previousRank = draw_a_card();

        for ( i = 0; i < rounds; i++) {

            while ( true ) {
                userGuess = 0;
                cout << "Higher (1) or Lower (2)?: ";
                cin >> userGuess;

                if (userGuess == 1 ) {
                        rank = draw_a_card();
                        if ( previousRank > rank ) {
                            score--;
                        } else if ( previousRank < rank ) {
                            score++;
                        } 
                        previousRank = rank;
                        break;
                }
                 else if ( userGuess == 2 ) {
                        rank = draw_a_card();
                        if ( previousRank > rank ) {
                            score++;
                        } else if ( previousRank < rank ) {
                            score--;
                        } 
                        previousRank = rank;
                        break;
                 } else {      
                        cout << "Please enter enter 1 or 2" << endl;
                  }
         }
            cout << "score = " << score << endl ;
            cout << "iteration" << i << endl;
        }     
    
    
        if ( score > 0 ) {
            cout << "You Win with a score of " << score << "!" << endl;
        } else if ( score < 0 ) {
            cout << "It was a tie" << endl;
        } else {
            cout << "You lose, your score was " << score << endl;
        }
    }
    return 0;
}
        



/*Draw-a-card function
 * Perform a card draw by getting a random 0-4 and random 0-12. Use these to 
 * index the strings arrays, ranks and suits.
 */
int draw_a_card() {
    int r, s, n, card;
    
    n = rand_0toN1(cards_remaining--);
    card = select_next_available(n);
    
    r = card % 13;
    s = card / 13;
    
    cout << ranks[r] << " of " << suits[s] << endl;
    
    return r;
}


/* Select-next-available-card function
 * Find the Nth element of card_drawn, skipping over those elements already set 
 * true
 */
int select_next_available (int n ) {
    
    int i = 0;
    
    // At beginning of deck, skip cards already drawn
    
    while (card_drawn[i]) {
        i++;
    }
    
    while ( n-- > 0 ) {                 //Do the following n times:
        i++;                            //Advance to next card
        while (card_drawn[i]) {         //Skip past cards
            i++;                        //already drawn
        }
    }
    
    card_drawn [i] = true;              //Note card to be 
    
    return i;                           //return this number

}

/*Random 0-to-N1 Function
 * Generate a random integer from 0 to N-1
 */
int rand_0toN1 (int n) {
    return rand() % n;
}