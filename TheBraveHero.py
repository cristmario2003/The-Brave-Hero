import random

carl = {"Viata": random.randint(65, 95), "Putere": random.randint(60, 70), "Aparare": random.randint(40, 50), "Viteza": random.randint(40, 50), "Noroc": random.randint(10, 30)}

print("Viata lui Carl este:", carl["Viata"])
print("Puterea lui Carl este:", carl["Putere"])
print("Apararea lui Carl este:", carl["Aparare"])
print("Viteza lui Carl este:", carl["Viteza"])
print("Norocul lui Carl este:", carl["Noroc"])

print()

bestie = {"Viata": random.randint(55, 90), "Putere": random.randint(50, 80), "Aparare": random.randint(35, 55), "Viteza": random.randint(40, 60), "Noroc": random.randint(25, 40)}

print("Viata bestiei este:", bestie["Viata"])
print("Puterea bestiei este:", bestie["Putere"])
print("Apararea bestiei este:", bestie["Aparare"])
print("Viteza bestiei este:", bestie["Viteza"])
print("Norocul bestiei este:", bestie["Noroc"])

print()

if carl["Viteza"] > bestie["Viteza"]:
    ok = 1
    print("Carl ataca primul.", '\n')
elif bestie["Viteza"] > carl["Viteza"]:
    ok = 0
    print("Bestia ataca prima.", '\n')
else:
    if carl["Noroc"] >= bestie["Noroc"]:
        ok = 1
        print("Carl ataca primul.", '\n')
    else:
        ok = 0
        print("Bestia ataca prima.", '\n')

NumarTure = 0

while carl["Viata"] > 0 and bestie["Viata"] > 0 and NumarTure < 20:
    NumarTure += 1
    print("Inceputul turului cu numarul {0}:".format(NumarTure))
    if ok == 1:
        print("\tEste randul lui Carl sa atace.")

        dodge = random.randint(1, 100)

        if dodge <= bestie["Noroc"]:
            print("\tBestia are noroc si se fereste de atac.")

        else:
            abilitate = random.randint(1, 100)

            if abilitate <= 10:
                print("\tCarl foloseste forta dragonului pentru a-si dubla puterea.")

                if carl["Putere"] * 2 - bestie["Aparare"] <= 0:
                    print("\tAtacul lui Carl nu ii provoaca daune bestiei.")

                elif carl["Putere"] * 2 - bestie["Aparare"] >= 100:
                    bestie["Viata"] -= 100
                    print("\tAtacul lui Carl ii provoaca bestiei daune in valoare de 100.")

                else:
                    bestie["Viata"] = bestie["Viata"] - (carl["Putere"] * 2 - bestie["Aparare"])
                    print("\tAtacul lui Carl ii provoaca bestiei daune in valoare de {0}.".format(carl["Putere"] * 2 - bestie["Aparare"]))

            else:
                if carl["Putere"] - bestie["Aparare"] <= 0:
                    print("\tAtacul lui Carl nu ii provoaca daune bestiei.")

                elif carl["Putere"] - bestie["Aparare"] >= 100:
                    bestie["Viata"] -= 100
                    print("\tAtacul lui Carl ii provoaca bestiei daune in valoare de 100.")

                else:
                    bestie["Viata"] = bestie["Viata"] - (carl["Putere"] - bestie["Aparare"])
                    print("\tAtacul lui Carl ii provoaca bestiei daune in valoare de {0}.".format(carl["Putere"] - bestie["Aparare"]))

        ok = 0
        print("\tBestia ramane cu {0} puncte de viata.".format(bestie["Viata"]))

    else:
        print("\tEste randul bestiei sa atace.")

        dodge = random.randint(1, 100)

        if dodge <= carl["Noroc"]:
            print("\tCarl are noroc si se fereste de atac.")

        else:
            abilitate = random.randint(1, 100)

            if abilitate <= 20:
                print("\tCarl foloseste scutul fermecat pentru a-si injumatati daunele primite.")

                if bestie["Putere"] // 2 - carl["Aparare"] <= 0:
                    print("\tAtacul bestiei nu ii provoaca daune lui Carl.")

                elif bestie["Putere"] // 2 - carl["Aparare"] >= 100:
                    carl["Viata"] -= 100
                    print("\tAtacul bestiei ii provoaca daune lui Carl in valoare de 100.")

                else:
                    carl["Viata"] = carl["Viata"] - (bestie["Putere"] // 2 - carl["Aparare"])
                    print("\tAtacul bestiei ii provoaca lui Carl daune in valoare de {0}.".format(bestie["Putere"] // 2 - carl["Aparare"]))

            else:
                if bestie["Putere"] - carl["Aparare"] <= 0:
                    print("\tAtacul bestiei nu ii provoaca daune lui Carl.")

                elif bestie["Putere"] - carl["Aparare"] >= 100:
                    carl["Viata"] -= 100
                    print("\tAtacul bestiei ii provoaca daune lui Carl in valoare de 100.")

                else:
                    carl["Viata"] = carl["Viata"] - (bestie["Putere"] - carl["Aparare"])
                    print("\tAtacul bestiei ii provoaca lui Carl daune in valoare de {0}.".format(bestie["Putere"] - carl["Aparare"]))

        ok = 1
        print("\tCarl ramane cu {0} puncte de viata.".format(carl["Viata"]))

    print()

if carl["Viata"] <= 0:
    print("Bestia l-a infrant pe Carl dupa {0} ture, ramanand cu {1} puncte de viata.".format(NumarTure, bestie["Viata"]))

elif bestie["Viata"] <= 0:
    print("Carl a infrant bestia dupa {0} ture, ramanand cu {1} puncte de viata.".format(NumarTure, carl["Viata"]))

elif NumarTure == 20:
    print("Cele 20 de ture s-au terminat si Carl a ramas cu {0} puncte de viata si bestia cu {1} puncte de viata.".format(carl["Viata"], bestie["Viata"]))

