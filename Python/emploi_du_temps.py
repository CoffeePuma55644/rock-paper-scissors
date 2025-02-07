emploi_du_temps = {
    "Lundi" : [],
    "Mardi" : [],
    "Mercredi" : [],
    "Jeudi" : [],
    "Vendredi" : [],
    "Samedi" : [],
}

while True:
    print("Logiciel de gestion d'emploi du temps !")
    print("Choisissez votre option !")
    print("1. Ajouter un cours et une heure...")
    print("2. Supprimer un cours")
    print("3. Afficher l'emploi du temps")
    print("4. Quitter")
    
    choix = int(input("Entrez votre choix: "))
    
    if choix == 1:
        # Ajouter un cours et une heure
        jour = input("Choisissez le jour: ")
        if jour in emploi_du_temps:
            cours = input("Entrez le nom du cours : ")
            heure = input("Entrez l'heure du cours: ")
            emploi_du_temps[jour].append((cours, heure))
            print(f"Cours ajouté pour {jour}: {cours} à {heure}")
        else:
            print("Jour invalide. Veuillez réessayer.")
            
    elif choix == 2:
        # Supprimer un cours
        jour = input("Entrez le jour à consulter: ")
        if jour in emploi_du_temps:
            print(f"Emploi du temps pour {jour}: {emploi_du_temps[jour]}")
            cours_index = int(input("Entrez l'index du cours à supprimer: "))
            if 0 <= cours_index < len(emploi_du_temps[jour]):
                del emploi_du_temps[jour][cours_index]
                print("Cours supprimé avec succès.")
            else:
                print("Index invalide. Veuillez réessayer.")
        else:
            print("Jour invalide. Veuillez réessayer.")
    
    elif choix == 3:
        # Afficher l'emploi du temps
        for jour, cours in emploi_du_temps.items():
            print(f"{jour}: {cours}")
    
    elif choix == 4:
        # Quitter le programme
        print("Au revoir!")
        break
    
    else:
        # Choix invalide
        print("Choix invalide. Veuillez réessayer.")