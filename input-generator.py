from faker import Faker

fake = Faker()

with open("entrada.dat", "w+", encoding='utf-8') as f:
    for i in range(50):
        f.write(fake.text(max_nb_chars=20) + ",")    # key
        f.write(fake.text(max_nb_chars=50, ext_word_list=None) + "\n")   # content
