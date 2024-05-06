import matplotlib.pyplot as plt
import csv

class d:
    def __init__(self, data_file_path):
        self.year = []
        self.variation = []
        self.load_data(data_file_path)

    def load_data(self, data_file_path):
        with open(data_file_path) as data_file:
            data_reader = csv.reader(data_file, delimiter=',')
            next(data_reader)  # Salta l'intestazione
            for row in data_reader:
                self.year.append(int(row[0]))
                self.variation.append(float(row[1]))

    def plot(self):
        plt.figure(figsize=(10, 6))
        plt.plot(self.year, self.variation, color='Blue', linestyle='-', marker='o', markersize=5)
        plt.title('sea level increasing')
        plt.xlabel('Year')
        plt.ylabel('Variation (mm)')
        plt.grid(True)
        plt.show()

if __name__ == "__main__":
    data_file_path = "./SeaLevel.csv"
    plotter = GlobalWarmingPlotter(data_file_path)
    plotter.plot()
