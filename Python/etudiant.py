liste_etudiant = []
filiere_etudiant = []

def inscris(nom):
    liste_etudiant.append(nom)
    
def filiere(filiere):
    filiere_etudiant.append(filiere)
    
def supression_nom():
    liste_etudiant.pop()
    
def supression_filiere():
    filiere_etudiant.pop()
    
while True:
    
    print("\n Bienvenue dans le programme d'inscriotion !")
    print("Veuillez choisir une option")
    print("1. Ajouter un étudiant et sa filiere")
    print("2. Affichier les listes")
    print("3. Supprimer un étudiant")
    
    choix = int(input("Votre option ?: "))
    
    if choix == 1:
        nom = input("Entrez le nom de l'étudiant")
        faliere = input("Entrez sa filière")
        inscris(nom)
        filiere(faliere)
        print("Entrée avec succès !")
        
    elif choix == 2:
        print(liste_etudiant)
        print(filiere_etudiant)
        
    elif choix == 3:
        sup_nom = supression_nom()
        sup_filiere = supression_filiere()
        print(f"{sup_nom} de la filire de {sup_filiere} a été supprimé !")
        
    else:
        print("Choisissez un choix valide !")