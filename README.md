ver 1.0.150530: First version of Chinese chess

Known problems and possible improvements
----------------------------------------------------------------------------------------
· Once a chess is selected, players cannot deselect this chess even though it cannot perform any move.
· Players have to enter X/Y coordinates seperately.
· Players cannot surrender.
· The player may stuck when not of his/her remaining chesses can move, the system should anncounce his/her failure.

Game rules
----------------------------------------------------------------------------------------
http://en.wikipedia.org/wiki/Xiangqi#Rules

Chess board
----------------------------------------------------------------------------------------
In this version of Chinese chess, the chess board is displayed using Chinese characters and tabular characters. Tabular characters will only be displayed if a position is empty. In addition, horizontal coordinates (1 to 9) are displayed on the top of the chess board, and vertical coordinates (a to j) are displayed on the left of the chess board.

Gameplay
----------------------------------------------------------------------------------------
In this version of Chinese chess, the player needs to enter vertical coordinate and horizontal coordinate seperately to select a chess. After that, another set of coordinates needs to be entered to select a destination. If an enemy chess is at that position, it will be eaten by the selected chess; otherwise the selected chess will just move to that position. After the move or attack, the system will check whether the general (帅/将) is eaten. If one of them are eaten, the game will over; otherwise, the other player's turn will start.
