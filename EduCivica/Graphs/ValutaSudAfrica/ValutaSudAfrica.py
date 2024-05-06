import matplotlib.pyplot as plt
import csv

class ExchangeValuePlotter:
    def __init__(self, data_file_path):
        self.year = []
        self.value = []
        self.load_data(data_file_path)

    def load_data(self, data_file_path):
        with open(data_file_path) as data_file:
            data_reader = csv.reader(data_file, delimiter=',')
            next(data_reader)  # Salta l'intestazione
            for row in data_reader:
                self.year.append(int(row[0]))
                self.value.append(float(row[1]))

    def plot(self):
        plt.figure(figsize=(10, 6))
        plt.plot(self.year, self.value, color='Yellow', linestyle='-', marker='o', markersize=5)
        plt.title('Rand to Euro')
        plt.xlabel('Year')
        plt.ylabel('Value ZAR - EUR')
        plt.grid(True)
        plt.show()

if __name__ == "__main__":
    data_file_path = "./ValutaSudAfrica.csv"
    plotter = ExchangeValuePlotter(data_file_path)
    plotter.plot()
