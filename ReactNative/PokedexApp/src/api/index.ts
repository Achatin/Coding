import axios from 'axios';

const api = () => {
  return axios.create({
    baseURL: 'https://pokeapi.co/api/v2/',
  });
};

export default api;
