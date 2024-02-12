import React, { useEffect, useState } from 'react';
import clsx from 'clsx';
import Link from '@docusaurus/Link';
import useDocusaurusContext from '@docusaurus/useDocusaurusContext';
import Layout from '@theme/Layout';
import HomepageFeatures from '@site/src/components/HomepageFeatures';

import Heading from '@theme/Heading';
import styles from './index.module.css';

function HomepageHeader() {
  const {siteConfig} = useDocusaurusContext();
  const [latestReleaseUrl, setLatestReleaseUrl] = useState('');

  useEffect(() => {
    async function fetchLatestRelease() {
      try {
        const response = await fetch('https://api.github.com/repos/fakuzatsu/verdant-emerald/releases/latest');
        const data = await response.json();
        const downloadUrl = data.assets[0].browser_download_url; // Assuming you want to use the first asset's download URL
        setLatestReleaseUrl(downloadUrl);
      } catch (error) {
        console.error('Error fetching latest release:', error);
      }
    }

    fetchLatestRelease();
  }, []);
  return (
    <header className={clsx('hero hero--primary', styles.heroBanner)}>
      <div className="container">
        <Heading as="h1" className="hero__title">
          {siteConfig.title}
        </Heading>
        <p className="hero__subtitle">{siteConfig.tagline}</p>
        <div className={styles.buttons}>
          <a
            className="button button--secondary button--lg"
            href={latestReleaseUrl}
            target="_blank"
            rel="noopener noreferrer">
            Download Patch
          </a>
          <Link
            className="button button--secondary button--lg"
            to="/docs/intro">
            Visit the Docs
          </Link>
        </div>
      </div>
    </header>
  );
}

export default function Home() {
  const {siteConfig} = useDocusaurusContext();
  return (
    <Layout
      title={`Hello from ${siteConfig.title}`}
      description="Description will go into a meta tag in <head />">
      <HomepageHeader />
      <main>
        <HomepageFeatures />
      </main>
    </Layout>
  );
}
