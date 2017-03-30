# deckOfCards
You are given a deck containing n cards.  While holding the deck:  1. Take the top card off the deck and set it on the table 2. Take the next card off the top and put it on the bottom of the deck in your hand. 3. Continue steps 1 and 2 until all cards are on the table.  This is a round. 4. Pick up the deck from the table and repeat steps 1-3 until the deck is in the original order.  Determining how many rounds it will take to put a deck back into the original order. 

* Instruction of use of Application:
	* We are placing the cards facing down on table or while holding in hand
	* Please Enter number of cards in a deck between 1 to 52
	* run make for compiling and excute ./deckOfCards 
	* Add command line arguments as input for number of cards
	* make clean for cleaning object files and executable file
	* Output is rendered in stdout.

* Assumption:
	* Considering given a single deck maximum of 52 cards
	* Given deck is all unique

* Implementation:
	* When i take the top card off the deck and set it on table and take next card off the top and put it on bottom, we get a sequence from the statement.
	* For each time of deck in hand, 1..3..5..7.... indexed cards go on the table stack and then 2..6..10..14 and followed by 4..12..20... and so on.
	* So its basically its difference of index of 2 first, then 4, then 8, then 16 and so on for each time holding a deck in hand.

* Complexity:
	* For each round it takes O(N) time, so in total it would be k*O(N) (Where k = number of rounds and N is number of cards)
