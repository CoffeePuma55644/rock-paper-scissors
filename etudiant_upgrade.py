liste_etudiants = {}
i = 0

def inscription(nom, filiere):
    
    liste_etudiants[nom] = filiere
    print(f"{nom} de la filiere de {filiere} a été ajouté(e) avec succès !")

def supression_etudiant():
    print(liste_etudiants)
    option = input("Que voulez-vous supprimer ?: ")
    try:
        liste_etudiants.pop(option)
        pass
    except:
        print("Cet étudiant n'est pas dans la liste")
        
print("\n Bienvenue dans le logiciel de gestion d'étudiant !")

while True:
    
    
    print("\n 1. Ajout d'un étudiant")
    print("\n 2. Supprimer un étudiant")
    print("\n 3. Afficher la liste d'éudiant")
    print("\n 4. Quitter !")
    
    choix = int(input("Choisissez une option:  "))
    
    if choix == 1:
        nom = input("Entrez le nom de l'étudiant: ")
        filiere = input("Entrez la filière")
        inscription(nom, filiere)
        
    elif choix == 2:
        if len(liste_etudiants) == 0:
            print("La liste est vide.")
        else:
            supression_etudiant()
        
    elif choix == 3:
        
        print(liste_etudiants)
            
    elif choix == 4:
        print("Vous quittez le programme")
        break
    
    else:
        print("Veuillez entrez un choix valide !")
        