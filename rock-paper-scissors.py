import random 

player_wins = 0
computer_wins = 0

print("Let's play rock, paper or scissors")

while player_wins < 2 and computer_wins < 2:

  choices = ["rock", "paper", "scissors"]
  computer_choice = random.choice(choices)

  

  player_choice = input("Enter: 'rock', 'paper' or 'scissors'?: ").lower()

  print("Computer choice: ", computer_choice)

  if (player_choice == "rock" and computer_choice == "scissors") or (player_choice == "scissors" and computer_choice == "paper") or (player_choice == "paper" and computer_choice == "rock"):
    winner = "Player"
    

  elif player_choice == computer_choice:
    winner = "Tie"

  else:
    winner = "Computer"


  if winner == "Player":
    print("You Won")
    player_wins += 1

  elif winner == "Computer":
    print("Computer won")
    computer_wins += 1

  else:
    print("It's a tie")
  print(f"Current Score - Player: {player_wins}, Computer: {computer_wins}")

if player_wins > computer_wins:
  print("Congragulations! You won.")

else:
  print("Computer won!")