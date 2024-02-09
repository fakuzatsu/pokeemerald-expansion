import clsx from 'clsx';
import Heading from '@theme/Heading';
import styles from './styles.module.css';

const FeatureList = [
  {
    title: 'Emerald Expanded',
    Svg: require('@site/static/img/undraw_docusaurus_mountain.svg').default,
    description: (
      <>
        Verdant Emerald is built on the Pokeemerald-Expansion repo (details in docs).<br/><br/>
        Featuring all Pokémon, Moves, Abilities, Items, and Battle Gimmicks from Generation 1 to 8 (Z-Moves, Megas, Terrains, etc.).<br/><br/>
        All extra features have been distributed through the Hoenn region with great care taken to improve the regular playthrough experience.
      </>
    ),
  },
  {
    title: 'More Story, More Gameplay',
    Svg: require('@site/static/img/undraw_docusaurus_tree.svg').default,
    description: (
      <>
        Verdant Emerald features plenty of new and expanded maps, providing new ways to explore the region.<br/><br/>
        Encounter familiar trainers throughout your journey and engage in exciting new events to unlock special Pokémon, Items, Features, etc.<br/><br/>
        Engage in quests to unlock your favourite legendaries, throughout and after the main story.

      </>
    ),
  },
  {
    title: 'QoL. QoL Galore',
    Svg: require('@site/static/img/undraw_docusaurus_react.svg').default,
    description: (
      <>
        Verdant Emerald has been absolutely packed with Quality of Life changes that let you engage in the content you care about, and skip anything you don't.<br/><br/>
        Change your gameplay experience entirely with Level Caps/Challenges/Randomisation.<br/><br/>
        See your EVs/IVs, Nature stat-changes, use Move Tutor from the Party menu and way more.

      </>
    ),
  },
];

function Feature({Svg, title, description}) {
  return (
    <div className={clsx('col col--4')}>
      <div className="text--center">
        <Svg className={styles.featureSvg} role="img" />
      </div>
      <div className="text--center padding-horiz--md">
        <Heading as="h3">{title}</Heading>
        <p>{description}</p>
      </div>
    </div>
  );
}

export default function HomepageFeatures() {
  return (
    <section className={styles.features}>
      <div className="container">
        <div className="row">
          {FeatureList.map((props, idx) => (
            <Feature key={idx} {...props} />
          ))}
        </div>
      </div>
    </section>
  );
}
