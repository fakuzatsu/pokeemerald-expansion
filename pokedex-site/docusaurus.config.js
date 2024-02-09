// @ts-check
// `@type` JSDoc annotations allow editor autocompletion and type checking
// (when paired with `@ts-check`).
// There are various equivalent ways to declare your Docusaurus config.
// See: https://docusaurus.io/docs/api/docusaurus-config

require('dotenv').config();

import {themes as prismThemes} from 'prism-react-renderer';

/** @type {import('@docusaurus/types').Config} */
const config = {
  title: 'Verdant Emerald',
  tagline: 'With extra Verdance~',
  favicon: 'img/favicon.ico',

  // Production url of site.
  url: 'https://fakuzatsu.github.io',
  baseUrl: '/verdant-emerald/',

  // GitHub pages deployment config.
  organizationName: 'fakuzatsu',
  projectName: 'verdant-emerald',

  onBrokenLinks: 'throw',
  onBrokenMarkdownLinks: 'warn',

  i18n: {
    defaultLocale: 'en',
    locales: ['en'],
  },

  presets: [
    [
      'classic',
      /** @type {import('@docusaurus/preset-classic').Options} */
      ({
        docs: {
          sidebarPath: './sidebars.js',
        },
        blog: {
          showReadingTime: true,
        },
        theme: {
          customCss: './src/css/custom.css',
        },
      }),
    ],
  ],

  themeConfig:
    /** @type {import('@docusaurus/preset-classic').ThemeConfig} */
    ({
      // Replace with your project's social card
      image: 'img/docusaurus-social-card.jpg',
      navbar: {
        title: 'Verdant Emerald',
        logo: {
          alt: 'My Site Logo',
          src: 'img/logo.svg',
        },
        items: [
          {
            type: 'docSidebar',
            sidebarId: 'tutorialSidebar',
            position: 'left',
            label: 'Docs',
          },
          {to: '/blog', label: 'Updates', position: 'left'},
          {
            href: 'https://github.com/fakuzatsu/verdant-emerald',
            label: 'GitHub',
            position: 'right',
          },
        ],
      },
      footer: {
        style: 'dark',
        links: [
          {
            title: 'Docs',
            items: [
              {
                label: 'Index',
                to: '/docs/intro',
              },
              {
                label: 'Pokedex',
                to: '/docs/intro',
              },
            ],
          },
          {
            title: 'Community',
            items: [
              {
                label: 'Verdant Emerald Discord',
                href: 'https://fakuzatsu.github.io/verdant-emerald/',
              },
              {
                label: 'RHH Discord',
                href: 'https://discord.gg/6CzjAG6GZk',
              },
            ],
          },
          {
            title: 'More',
            items: [
              {
                label: 'Blog',
                to: '/blog',
              },
              {
                label: 'GitHub',
                href: 'https://github.com/fakuzatsu/verdant-emerald',
              },
            ],
          },
        ],
        copyright: `Copyright © ${new Date().getFullYear()} Fakuzatsu. Built with Docusaurus.`,
      },
      prism: {
        theme: prismThemes.github,
        darkTheme: prismThemes.dracula,
      },
    }),
};

export default config;
