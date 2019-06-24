from faker import Faker

fake = Faker()

n = input();
if n == '\n':
    n = 50;
n = int(n)


with open("entrada.dat", "w+", encoding='utf-8') as f:
    for i in range(n):
        f.write(fake.text(max_nb_chars=20) + ",")    # key
        f.write(fake.text(max_nb_chars=50, ext_word_list=None) + "\n")   # content
