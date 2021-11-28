const getPokemonIdFromUrl = (url: string) => {
  const split = url.split('/');

  return Number(split[split.length - 2]);
};

export default getPokemonIdFromUrl;
