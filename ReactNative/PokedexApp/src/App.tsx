import {
  BottomTabNavigationOptions,
  createBottomTabNavigator,
} from '@react-navigation/bottom-tabs';
import { NavigationContainer } from '@react-navigation/native';
import { createNativeStackNavigator } from '@react-navigation/native-stack';
import React from 'react';
import Icon from 'react-native-vector-icons/Ionicons';
import PokeballIcon from './assets/icons/Pokeball';
import Home from './screens/Home';
import PokemonList from './screens/PokemonList';
import PokemonDetail from './screens/PokemonDetail';
import colors from './styles/colors';
import { capitalizeFirstLetter } from './utils';

type TabParamsList = {
  Home: undefined;
  Pokedex: undefined;
};

export type PokemonStackParamList = {
  PokemonList: undefined;
  PokemonDetail: {
    id: number;
    name: string;
  };
};

const AppTab = createBottomTabNavigator<TabParamsList>();
const PokedexStack = createNativeStackNavigator<PokemonStackParamList>();

const PokedexStackScreen = () => {
  return (
    <PokedexStack.Navigator
      initialRouteName="PokemonList"
      screenOptions={{
        headerStyle: { backgroundColor: colors.redRibbon },
        headerTintColor: colors.amber,
      }}
    >
      <PokedexStack.Screen
        name="PokemonList"
        component={PokemonList}
        options={{
          headerTitle: 'Pokédex',
        }}
      />
      <PokedexStack.Screen
        name="PokemonDetail"
        component={PokemonDetail}
        options={({ route }) => ({
          headerTitle: capitalizeFirstLetter(route.params.name),
        })}
      />
    </PokedexStack.Navigator>
  );
};

const App = () => {
  const screenOptions: BottomTabNavigationOptions = {
    headerShown: false,
    headerStyle: { backgroundColor: colors.redRibbon },
    headerTintColor: colors.amber,
    tabBarAllowFontScaling: true,
    tabBarStyle: { backgroundColor: colors.redRibbon },
    tabBarActiveTintColor: colors.amber,
    tabBarInactiveTintColor: colors.mercury,
  };

  return (
    <NavigationContainer>
      <AppTab.Navigator initialRouteName="Home" screenOptions={screenOptions}>
        <AppTab.Screen
          options={{
            tabBarIcon: ({ color, size }) => (
              <Icon name="home" color={color} size={size} />
            ),
          }}
          name="Home"
          component={Home}
        />
        <AppTab.Screen
          options={{
            tabBarIcon: ({ color }) => <PokeballIcon color={color} />,
            tabBarLabel: 'Pokédex',
          }}
          name="Pokedex"
          component={PokedexStackScreen}
        />
      </AppTab.Navigator>
    </NavigationContainer>
  );
};

export default App;
