import React from 'react';
import { View, Text } from 'react-native';
import { transformDashedText } from '../../utils';
import Label from '../Label/Label';

type ListItem = {
  name: string;
};

type Props = {
  label: string;
  list: ListItem[];
};

const InfoList = ({ label, list }: Props) => {
  return (
    <View>
      <Label>{label}</Label>
      <View>
        {list.map((item) => {
          return <Text key={item.name}>{transformDashedText(item.name)}</Text>;
        })}
      </View>
    </View>
  );
};

export default InfoList;
