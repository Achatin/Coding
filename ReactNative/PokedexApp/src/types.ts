export type PokemonListItem = {
  entry_number: number;
  pokemon_species: {
    name: string;
    url: string;
  };
};

export type Stat = {
  base_stat: number;
  effort: number;
  stat: {
    name: string;
  };
};

export type Move = {
  move: {
    name: string;
  };
};

export type Ability = {
  ability: {
    name: string;
  };
};

export type Type = {
  type: {
    name: string;
  };
};

export type Pokemon = {
  id: number;
  name: string;
  height: number;
  weight: number;
  stats: Stat[];
  moves: Move[];
  abilities: Ability[];
  types: Type[];
};
