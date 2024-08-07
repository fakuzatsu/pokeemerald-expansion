# Define the Python interpreter
PYTHON = python3

# Define the script to run
SPECIES = alphabetical_species.py
#ITEMS = alphabetical_items.py

# Default target
all: species_script

# Rule to run the Python script
species_script:
	$(PYTHON) $(SPECIES)

#item_script:
#	$(PYTHON) $(ITEMS)

# Clean target to remove generated files
clean:
	rm -f ../../incude/alphabetical_species.h

# PHONY targets
.PHONY: all species_script clean
