# Connect Four
1.  Rules Of The Game
Connect four is played by two players on a 6(rows) * 7(columns) chessboard. Each turn, one player drop one unique color disc inside the chessboard to occupy one position of the chessboard. The one who set 4 discs on a line no matter horizontally, vertically or diagonally firstly, win.
       	
2.  Graphical Users Interface
There are start window, cheeseboard, replay button, credits button and message box to interact with users. Once, the program is started, it accompany with attractive image and music.
Start window, users choose one model to start. We provide two versions for users to choose, one is person versus person for users to play with friend each other; other one is person versus artificial intelligence.
Chessboard. It is 6(rows) * 7(columns), totally 42 cells on the chessboard. The chessboard is sensitive to the signal of mouse column by column, because each time, the user can only drop one disc on the chessboard to the bottom of column. Each turn, only one player can drop one disc on the chessboard.
Replay button. Literally, this button permits only users to sweep away all the discs on the chessboard no matter owns or opponent’s to restart the game.
Credits button. This button allows users to get the information of our team name and team members. It gives credits to us for our creature to this product.
Message box. At each step, the program would judge the result of the game. As long as one side has 4 same color discs on a line, the message box will show up to indicate the consequence of the competition. If the message box appears, the game will be terminated. Users need to click the “OK” button on the middle of the message box or close button to close this window. And then, clicking the “Replay” button to restart the game.

3.  Artificial Intelligence
There is an artificial intelligence (AI) in this program to versus with human players. Human player always be the first one to drop the disc. At the each turn of the AI, the AI is going to predict the game in 4 steps or turns forward from the current column to decide whether dropping disc in this column in current turn. In other word, the AI calculates 7^5 = 16807 each turn to find out the optional position. For each current column position, the AI will simulate that it drops disc on this position. In the further 4 steps, the simulation returns each color discs’ connecting situation.
The last(fourth) step feeds back all 7^4 = 2401 positions’ information that each color has how many discs connects together, summing 7 of them as group to pass it to the previous step. 
The last but one(third) step, one of the 7^3 = 343 potential positions collects all the information from the previous 2401 potential positions as 7 a group to itself. And then, summing 7 of the 343 as a group to pass to the previous step. There should have 49 groups, which is the same number of the last but three step. 
The last but three(second) and first collect information in the same way. Then, the current column would get a value. Each of the seven possible current columns has a own value. Finding the max value of these seven, this column is the goal.
Simultaneously, on the futuer every one step, the AI would to decide the stratagy of aggression or defense. At each simulating step, once the simulating chessboard appears four same color discs, if they are red, the AI will return a huge value to the previous step untill the current column and stop keeping simulating process; if they are black, the AI will return a very tiny value to the previous step untill the current column and stop keeping simulating process.

