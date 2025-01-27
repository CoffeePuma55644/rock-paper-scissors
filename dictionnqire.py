notes_de_jeux = {
    "variable": 17,
    "variable1": 18,
    "League of Legends": "C'est nul !" ,
    "Marvel": True,
}
somme = notes_de_jeux["variable"] + notes_de_jeux["variable1"]




notes_de_jeux["Zelda"] = "Tears of the Kingdom"

if notes_de_jeux["Marvel"] == False:
    notes_de_jeux["Marvel"] = False
    
notes_de_jeux.pop("League of Legends")

for jeu in notes_de_jeux:
    print(f"Le jeu est {notes_de_jeux[jeu]} !")