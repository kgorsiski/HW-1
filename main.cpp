//
//  main.cpp
//  deck_f
//
//  Created by Kyle Gorsiski on 2/7/17.
//  Copyright © 2017 Kyle Gorsiski. All rights reserved.
//

#include <iostream>
#include <assert.h>
#include <random>
#include <time.h> 
#include <vector>
#include <fstream>


using namespace std;

int deckamount = 2; // Amount of decks being used
int cardamount = 52 * deckamount; // Total number of cards being used


class Deck{ // declaring the class Deck
public:
    int suit; // declaring the integer suit
    int rank; // declaring the integer rank
}; // end class Deck

class Card{ // declaring the class Card
public:
    int suit;
    int rank;
}; // end class Card

void deckshuffle(vector<Deck>* deck){ // Shuffle function
    
    for(int i = 0; i < cardamount; i++){
        
        /* These two lines are taking two random positions within the bounds of the amount of cards there are */
        int randone = rand() % ( cardamount );
        int randtwo = rand() % ( cardamount );
        
        for(int i = 0; i < cardamount; i++){
            Deck swapcard; // Creating a class object that will be a temporary placeholder so that I can switch cards around to shuffle them
            
            /* Shuffling the card ranks */
            
            swapcard.rank = deck->at(randone).rank; // defining the temporary card with the information from random position one
            deck->at(randone).rank = deck->at(randtwo).rank; // overwriting the random position one with the information from random position two
            deck->at(randtwo).rank = swapcard.rank; // overwriting the random position two with the stored information on the temporary card
            
            /* Shuffling the card suits  - same as above, but with suits instead of ranks */
            
            swapcard.suit = deck->at(randone).suit;
            deck->at(randone).suit = deck->at(randtwo).suit;
            deck->at(randtwo).suit = swapcard.suit;
        } // end for
    } // end for
} // end void


void Fxn_A(vector<Deck>* testdeckA){ // check for duplicates by comparing cards to eachother
    
    /* Creating two test cards */
    Card one;
    Card two;
    
    if(testdeckA->size() > 52){ // If the test deck has a size larger than 52, then that means there is more than one deck.
        cout << "Only one deck is allowed for function A." << endl; // Output text saying that you need to have only one deck for test A.
    } // end if
    
    else{
        
        for(int i = 0; i < cardamount; i++){
            
            for( int j = i+1; j < cardamount; j++){
                
                /* Assigning suits and ranks to the two test cards */
                    one.suit = testdeckA->at(i).suit;
                    one.rank = testdeckA->at(i).rank;
                    two.suit = testdeckA->at(j).suit;
                    two.rank = testdeckA->at(j).rank;
                }// end else
            
            
             /* initializing my booleans */
                bool samesuit = false;
                bool samerank = false;
                bool samecard = false;
                
                if(one.suit == two.suit){
                    samesuit = true; // if the suit of the two cards is the same, returns a true boolean.
                }//end if
                
                if(one.rank == two.rank){
                    samerank = true; // if the rank of the two cards is the same, returns a true boolean.
                }// end if
                
                if(samesuit == true && samerank == true){
                    samecard = true; // if both the rank and the suit of the cards is the same, returns a true boolean.
                }// end if
                
                if(samecard == true){ // if the third boolean is true, then that means there is a duplicate card in the test deck, meaning that there was an error shuffling the one deck, thus failing test A.
                    cout << "These are the same card." << "\t";
                    cout << "Function A has failed the test." << endl;
                    assert(1 == 0); // spits out error code if test fails.
                } // end if
                
                else{
                    cout << "No duplicate cards." << "\t"; // if the third boolean is false, outputs text saying there are no duplicates and that the test is passed.
                    cout << "Function A has passed the test." << endl;
                    assert(0 == 0);
                }// end else
            }// end for
        }// end for
} // end void

void Fxn_B(vector<Deck>* testdeckB){
    
    /* Creating two test cards */
    Card one;
    Card two;
    
    if(testdeckB->size() < 53){ // if the test deck size is below 53, then that means there aren't multiple decks in the stack, thus not meeting the conditions for test B.
        cout << "Multiple decks are required for Function B." << endl; // outputs text saying that you need to meet the conditions of the test
    } // end if
    
    else{
        int n = 0; // Setting initial counter for amount of times card shows up
        for(int i = 0; i < cardamount; i++){
            
            /* Assigning suits and ranks to the two test cards */
                one.suit = testdeckB->at(0).suit;
                one.rank = testdeckB->at(0).rank;
                two.suit = testdeckB->at(i).suit;
                two.rank = testdeckB->at(i).rank;
                
            /* Initializing my booleans */
            bool samesuit = false;
            bool samerank = false;

                
                if(one.suit == two.suit){ // comparing suits of the two cards
                    samesuit = true; // returns true boolean if both cards share suit
                }//end if
                
                if(one.rank == two.rank){
                    samerank = true; // returns true boolean if both cards share rank
                }// end if
                
                if(samesuit == true && samerank == true){// If both the booleans are true, then that means there is a duplicate card.
                    n = n + 1; // Add one to the counter of how many times that card shows up
                }// end if
        } // end for
        int nb = testdeckB->size() / 52; // Take the size of the test deck and divide by 52 to get the number of decks used in the test
        assert(n == nb); // compare the number of decks used in the test to the number of decks counted by the loop
       
        /*outputting information about the test and whether or not it passed */
        
        cout << "There are " << n << " amount of Suit: " << one.suit << "\t Rank: " << one.rank <<  " being used." << endl;
        cout << "There are " << n << " amount of decks being used." << endl;
        cout << "Function B has passed the test. " << endl;
    
    }// end else
}// end void

            
       

    




int main() {
     srand(time(NULL)); // creating a random seed
    
    int rankindex = 1; // Using Ace = 1, the rank index starts at 1
    int suitindex = 0; // Using suits of 0, 1, 2, 3. Suit index starts at 0
    int rankmax = 14; // Max size the rank can go to
    int suitmax = 4; // Max size the suit can go to
    
    vector<Deck> deck; // creating a vector of class Deck called deck
    
    /* Creating and populating the deck vector */
    
    for(int k = 0; k < deckamount; k++){
        for(int i = rankindex; i < rankmax; i++){
            for(int j = suitindex; j < suitmax; j++){
                Deck card;
                card.rank = i;
                card.suit = j;
                deck.push_back(card);
            }// end for
        } // end for
    }// end for
    
   
    /* Outputs the complete deck before it is shuffled. */
    
    cout << "\t Deck before shuffling: " << endl;
    for(int i = 0; i < cardamount; i++){
        
        cout << "Suit: " << deck.at(i).suit << "\t";
        cout << "Rank: " << deck.at(i).rank << endl;
    } // end for
    
    vector<Deck>* pdeck = &deck; // creates a pointer pdeck
    
    deckshuffle(pdeck); // uses the shuffle function on the pointer from the previous line
   
    /* Confirmation that shuffle function is not spitting out error */
    
    cout << "\t Deck is being shuffled..." << endl;
    assert (0 == 0);
    
    /* Performing Test A and Test B with the shuffled deck */
    
    Fxn_A(pdeck);
    Fxn_B(pdeck);
    
    /* Creating and printing the shuffled deck */
    ofstream myfile;
    myfile.open("ME493_HW1.txt");
    for(int i = 0; i < cardamount; i++){
          myfile << "Position: " << i << "\t Suit: " << pdeck->at(i).suit << "\t Rank: " << pdeck->at(i).rank << endl;
    }
    myfile.close();
    
    
    return 0;
} // end main
