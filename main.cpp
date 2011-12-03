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
void play_HigherLower();

bool card_drawn[52];
int cards_remaining = 52;

string suits[4] = {"hearts", "diamonds", "spades", "clubs"};
string ranks[13] = {"ace", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "jack", "queen", "king"};


int main() {
    play_HigherLower();
}

void play_HigherLower() {
    srand(time(NULL));

    int rounds, i, rank, previousRank, userGuess;
    int rightGuess =0, wrongGuess = 0, tied = 0;
    double score;
    
    //set all the variables so no cards have been drawn
    for (int i = 0; i < 52; i++ ){
        card_drawn[i] = false;
    }
    
    while (true ) {
        cout << endl << "Welcome to Higher or lower" << endl;
        cout << "you will be given a card and you have to guess if ";
        cout << "the next one is going to be higher or lower" << endl;
        cout << "How many cards do you want to draw? (0 to exit): ";
        cin >> rounds;
        
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
                            wrongGuess++;
                        } else if ( previousRank < rank ) {
                            rightGuess++;
                        } else {
                            tied++;
                        }
                        previousRank = rank;
                        break;
                }
                 else if ( userGuess == 2 ) {
                        rank = draw_a_card();
                        if ( previousRank > rank ) {
                            rightGuess++;
                        } else if ( previousRank < rank ) {
                            wrongGuess++;
                        } else {
                            tied++;
                        }
                        previousRank = rank;
                        break;
                 } else {      
                        cout << "Please enter enter 1 or 2" << endl;
                  }
             }
        }     
        
        score = (rightGuess/(rightGuess + tied + wrongGuess))*100;
    
        cout <<"Here are your Stats:"<< endl;
            cout << "# of right answers = " << rightGuess << endl;
            cout << "# of Wrong answers = " << wrongGuess << endl;
            cout << "# of Ties = " << tied << endl;
            cout << "Percentage of right answers: " << score << endl;
            
        if ( rightGuess > wrongGuess ) {
            cout << "You Win! you could be psychic :)"  << endl;
        } else if ( rightGuess < wrongGuess ) {
            cout << "You Lose :( try guessing better next time" << endl;
        } else {
            cout << "You tied, almost but still no win for you";
        }
    }
    return;
}
        



/*Draw-a-card function
 * Perform a card draw by getting a random 0-4 and random 0-12. Use these to 
 * index the strings arrays, ranks and suits.
 */
int draw_a_card() {
    int r, s, n, card;
    
    if (cards_remaining == 0 ){
        cout << "Reshuffling" << endl;
        cards_remaining = 52;
        
        //set all the variables so no cards have been drawn
        for (int i = 0; i < 52; i++ ){
            card_drawn[i] = false;
        }
    }
    
    
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