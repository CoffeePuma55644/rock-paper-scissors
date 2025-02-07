import tkinter as tk
from tkinter import messagebox

# Initialisation de l'emploi du temps
emploi_du_temps = {
    "Lundi" : [],
    "Mardi" : [],
    "Mercredi" : [],
    "Jeudi" : [],
    "Vendredi" : [],
    "Samedi" : [],
}

# Fonction pour ajouter un cours
def ajouter_cours():
    jour = jour_var.get()
    cours = cours_entry.get()
    heure = heure_entry.get()
    if jour in emploi_du_temps:
        emploi_du_temps[jour].append((cours, heure))
        messagebox.showinfo("Succès", f"Cours ajouté pour {jour}: {cours} à {heure}")
        cours_entry.delete(0, tk.END)
        heure_entry.delete(0, tk.END)
    else:
        messagebox.showerror("Erreur", "Jour invalide. Veuillez réessayer.")

# Fonction pour afficher l'emploi du temps
def afficher_emploi_du_temps():
    emploi_du_temps_str = ""
    for jour, cours in emploi_du_temps.items():
        emploi_du_temps_str += f"{jour}:\n"
        for c in cours:
            emploi_du_temps_str += f"  {c[0]} à {c[1]}\n"
    messagebox.showinfo("Emploi du temps", emploi_du_temps_str)

# Création de la fenêtre principale
root = tk.Tk()
root.title("Gestionnaire d'emploi du temps")

# Widgets pour ajouter un cours
tk.Label(root, text="Jour:").grid(row=0, column=0)
jour_var = tk.StringVar(root)
jour_var.set("Lundi")
tk.OptionMenu(root, jour_var, *emploi_du_temps.keys()).grid(row=0, column=1)

tk.Label(root, text="Cours:").grid(row=1, column=0)
cours_entry = tk.Entry(root)
cours_entry.grid(row=1, column=1)

tk.Label(root, text="Heure:").grid(row=2, column=0)
heure_entry = tk.Entry(root)
heure_entry.grid(row=2, column=1)

tk.Button(root, text="Ajouter cours", command=ajouter_cours).grid(row=3, column=0, columnspan=2)

# Bouton pour afficher l'emploi du temps
tk.Button(root, text="Afficher emploi du temps", command=afficher_emploi_du_temps).grid(row=4, column=0, columnspan=2)

# Bouton pour quitter l'application
tk.Button(root, text="Quitter", command=root.quit).grid(row=5, column=0, columnspan=2)

# Lancement de la boucle principale
root.mainloop()