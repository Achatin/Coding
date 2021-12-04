import { capitalizeFirstLetter } from '.';

const transformDashedText = (text: string) => {
  return capitalizeFirstLetter(text.replace('-', ' '));
};

export default transformDashedText;
