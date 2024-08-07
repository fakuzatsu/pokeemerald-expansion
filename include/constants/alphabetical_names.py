import re

def parse_species_header(filename):
    species_dict = {}
    with open(filename, 'r') as file:
        for line in file:
            if '#define FORMS_START' in line:
                break
            match = re.match(r'#define\s+SPECIES_(\w+)\s+(\d+)', line)
            if match:
                species_name, species_id = match.groups()
                species_name = species_name.split('_')[0]  # Handle cases like SPECIES_PIKACHU_SURFING
                species_name = species_name.capitalize()
                if species_name not in species_dict:
                    species_dict[species_name] = int(species_id)
    return species_dict

def generate_c_code(species_dict):
    sorted_species = sorted(species_dict.items())
    c_code = """typedef struct {
    const u8 *speciesName;
    int speciesID;
} SpeciesNameID;

static const SpeciesNameID speciesNamesWithID[] = {
"""
    for name, id_ in sorted_species:
        c_code += f'    ("{name}", SPECIES_{name.upper()}),\n'
    c_code += """};
"""
    return c_code

def main():
    filename = 'species.h'  # The input header file
    species_dict = parse_species_header(filename)
    c_code = generate_c_code(species_dict)
    
    with open('alphabetical_names.h', 'w') as file:
        file.write(c_code)
    
    print("Sorted array generated and written to alphabetical_names.h")

if __name__ == "__main__":
    main()
